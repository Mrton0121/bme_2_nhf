#include "texture_.h"
#include "node.h"
#include "edge.h"
#include "cmath"
#include "string"
#include "SDL2_gfxPrimitives.h"

using namespace std;

Texture::Texture(int x, int y, SDL_Color color) {
    this->x = x;
    this->y = y;
    this->color = color;
}

void Texture::draw(SDL_Renderer *renderer) {
    SDL_RenderDrawPoint(renderer,this->x,this->y);
}

Node::Node(NodeData node) : Texture(node.getCoord().x,node.getCoord().y, node.getColor()) {
    this->x = node.getCoord().x;
    this->y = node.getCoord().y;
    this->id = node.getId();
    this->color = node.getColor();
}

void Node::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, this->color.r,this->color.g,this->color.b,this->color.a);
    for(int x=this->x-15; x<=this->x+15; x++){
        for(int y=this->y-15; y<=this->y+15; y++){
            if((pow(this->y-y,2)+pow(this->x-x,2)) <=
               pow(15,2)){
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
    stringRGBA(renderer,this->x,this->y-25,this->id->c_str(),this->color.r,this->color.g,this->color.b,255);
    delete this->id;
}

Edge::Edge(EdgeData edge): Texture(edge.getSrc()->getCoord().x,edge.getSrc()->getCoord().y, edge.getColor()){
    Point src = edge.getSrc()->getCoord();
    this->type = edge.getType();
    if(this->type != LOOP){
        Point dst = edge.getDst()->getCoord();
        this->fx = dst.x;
        this->fy = dst.y;
    }
    else{
        this->fx = 0;
        this->fy = 0;
    }
    this->x = src.x;
    this->y = src.y;
    this->color = color;
}

void Edge::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, this->color.r,this->color.g,this->color.b,this->color.a);
    int start_x = this->x;
    int start_y = this->y;
    int end_x = this->fx;
    int end_y = this->fy;

    if(this->type == SIMPLE){
        SDL_RenderDrawLine(renderer,start_x,start_y,end_x,end_y);
    }
    if(this->type == DIRECTED){
        SDL_RenderDrawLine(renderer,start_x,start_y,end_x,end_y);

        // Nyíl koordináták kiszámolása
        int arrow_size = 10;
        float angle = atan2(end_y - start_y, end_x - start_x);
        int arrow1_x = end_x - arrow_size * cos(angle - M_PI / 6);
        int arrow1_y = end_y - arrow_size * sin(angle - M_PI / 6);
        int arrow2_x = end_x - arrow_size * cos(angle + M_PI / 6);
        int arrow2_y = end_y - arrow_size * sin(angle + M_PI / 6);

        // Rajzolunk két vonalat a nyíl két oldalán
        SDL_RenderDrawLine(renderer, end_x, end_y, arrow1_x, arrow1_y);
        SDL_RenderDrawLine(renderer, end_x, end_y, arrow2_x, arrow2_y);
    }
    if(this->type == LOOP){
        //Ezt a Bresenham-algoritmussal rajzolom
        int x = 0;
        int y = 30;
        int d = 3 - 2 * 30;

        while (x <= y) {
            SDL_RenderDrawPoint(renderer, start_x-20 + x, start_y-20 + y);
            SDL_RenderDrawPoint(renderer, start_x-20 + x, start_y-20 - y);
            SDL_RenderDrawPoint(renderer, start_x-20 - x, start_y-20 + y);
            SDL_RenderDrawPoint(renderer, start_x-20 - x, start_y-20 - y);
            SDL_RenderDrawPoint(renderer, start_x-20 + y, start_y-20 + x);
            SDL_RenderDrawPoint(renderer, start_x-20 - y, start_y-20 + x);
            SDL_RenderDrawPoint(renderer, start_x-20 + y, start_y-20 - x);
            SDL_RenderDrawPoint(renderer, start_x-20 - y, start_y-20 - x);

            if (d < 0) {
                d = d + 4 * x + 6;
            } else {
                d = d + 4 * (x - y) + 10;
                y--;
            }
            x++;
        }
    }
}

void TextureList::push(Texture *element) {
    this->len += 1;
    Texture** temp = new Texture*[this->length()];
    for(int i = 0; i < this->length()-1; i++){
        temp[i] = this->elements[i];
    }
    temp[this->length()-1] = element;
    delete[] this->elements;
    this->elements = temp;
}


