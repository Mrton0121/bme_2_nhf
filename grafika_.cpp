//
// Created by gombi on 2023.04.17..
//

#include "grafika_.h"

using namespace std;

Grafika::Grafika(const char* title, int x, int y, SDL_Color backgroundColor) {
    this->window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,x,y,SDL_WINDOW_INPUT_FOCUS);
    this->renderer = SDL_CreateRenderer(this->window,-1,0);
    setBackgroundColor(backgroundColor);
}

Grafika::~Grafika(){
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
}

void Grafika::await() {
    SDL_Event *event = new SDL_Event();
    bool ex = false;
    while(event->type != SDL_QUIT && !ex){
        SDL_PollEvent(event);
        if(event->type == SDL_KEYDOWN){
            ex = true;
        }
    }
    delete event;
}

void Grafika::setBackgroundColor(SDL_Color color) const {
    SDL_SetRenderDrawColor(renderer, color.r,color.g,color.b,color.a);
    SDL_RenderClear(renderer);
}
