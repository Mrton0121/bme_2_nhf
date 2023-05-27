//
// Created by gombi on 2023.04.17..
//

#ifndef HAZI_0328_TEXTURE_H
#define HAZI_0328_TEXTURE_H

#include <SDL.h>
#include "grafika_.h"
#include "Point.h"
#include "edge.h"
#include "node.h"

/**
 * Textúra ősosztály, ami a képernyőre való kirajzoláshoz szükséges adatokat tárolja.
 */
class Texture {
protected:
    int x;
    int y;
    SDL_Color color;
public:
    /**
     * Alapértelmezett konstruktor, ami minden értéket 0-ra állít. A példányosításhoz szükséges
     */
    Texture() : x(0), y(0), color({0,0,0,0}) {};
    /**
     * Másodlagos konstruktor. A megadott x és y koordinátákat valamint a textúra színét állítja be
     * @param x x koordináta
     * @param y y koordináta
     * @param color szín
     */
    Texture(int x, int y, SDL_Color color);
    /**
     * Virtuális tagfüggvény, amit az örököltetett Node és Edge osztály felülír.
     * @param renderer az SDL renderelő objektuma, amire rajzolunk.
     */
    virtual void draw(SDL_Renderer* renderer);
    /**
     * A textúra koordinátáját adja vissza
     * @return Point(x,y)
     */
    Point getCoord() {return {this->x, this->y};}
};

/**
 * A Texture osztályból örököltetett, csúcsokért felelős osztály.
 * Egy string típusú id mezővel egészíti ki az ősosztályt.
 */
class Node : public Texture{
    string *id;
public:
    /**
     * Alapértelmezett konstruktor.
     * A megadott NodeData osztály adatait felhasználva hozza létre az új objektumot.
     * @param node a NodeData, amelyikből létre akarjuk hozni a textúrát.
     */
    Node(NodeData node);
    /**
     * A Texture alaposztály virtuális függvényét felülíró függvény. Ez felel a kirajzolásáért a Node-nak
     * @param renderer az SDL renderelő objektuma, amire rajzolunk
     */
    void draw(SDL_Renderer* renderer) override;
};

/**
 * A Texture osztályból örököltetett, élekért felelős osztály.
 * Egy új koordináta párral és egy éltípussal egészíti ki az ősosztályt.
 */
class Edge : public Texture{
    int fx;
    int fy;
    EdgeType type;
public:
    /**
     * Alapértelmezett konstruktor. A megadott EdgeData segítségével tölti fel az adatait.
     * @param edge az EdgeData, aminek az adatait felhasználja.
     */
    Edge(EdgeData edge);
    /**
     * A Texture alaposztály virtuális függvényét felülíró függvény. Ez felel a kirajzolásáért az Edge-nek
     * @param renderer az SDL renderelő objektuma, amire rajzolunk
     */
    void draw(SDL_Renderer* renderer) override;
};

/**
 * A textúrák tárolásáért felelős heterogén kollekció osztálya.
 */
class TextureList{
    int len;
    Texture** elements;
    SDL_Renderer *renderer;
public:
    /**
     * Alapértelmezett konstruktor.
     * Létrehoz egy üres listát, valamint eltárolja a renderert, amire a későbbiekben rajzolni fog.
     * @param renderer az SDL renderelő objektuma, amire a rajzolást végezzük.
     */
    TextureList(SDL_Renderer *renderer){
        this->len = 0;
        this->elements = nullptr;
        this->renderer = renderer;
    }
    /**
     * Visszaadja a kollekció hosszát
     * @return len
     */
    const int length() const{
        return this->len;
    }
    /**
     * Visszaadja a kollekció elemeit
     * @return elements
     */
    Texture** getElements(){
        return this->elements;
    }

    void push(Texture *element);

    void render(){
        for(int i = 0; i < this->length(); i++){
            this->getElements()[i]->draw(this->renderer);
            delete this->getElements()[i];
        }
        SDL_RenderPresent(this->renderer);
    }

    ~TextureList(){
        delete[] this->elements;
    }
};

#endif //HAZI_0328_TEXTURE_H
