//
// Created by gombi on 2023.03.28..
//

#ifndef HAZI_0328_EDGE_H
#define HAZI_0328_EDGE_H

#include "node.h"
#include "SDL.h"
/**
 * Enumerátor, ami az élek típusának megkülönböztetéséért felel
 */
enum EdgeType{
    SIMPLE = 1,
    DIRECTED = 2,
    LOOP = 3,
};
/**
 * Az élek adatainak tárolására szolgáló osztály.
 * Tárolja a kezdő és végpontok csúcsadatait, az él típusát valamint az él színét.
 */
class EdgeData{
    NodeData *src;
    NodeData *dst;
    EdgeType type;
    SDL_Color color;

public:
    /**
     * Elsődleges konstruktor, ami az irányított és irányítatlan élek létrehozására szolgál
     * @param a kezdő csúcs adatai
     * @param b vége csúcs adatai
     * @param type az él típusa
     * @param color az él színe
     */
    EdgeData(NodeData *a, NodeData *b, EdgeType type, SDL_Color color){
        this->src = a;
        this->dst = b;
        this->type = type;
        this->color = color;
    }
    /**
     * Másodlagos konstruktor, ami a hurokélek létrehozására szolgál.
     * Ez a konstruktor automatikusan 'LOOP'-ra állítja az él típusát.
     * @param a
     * @param color
     */
    EdgeData(NodeData *a, SDL_Color color){
        this->src = a;
        this->dst = nullptr;
        this->type = LOOP;
        this->color = color;
    }
    /**
     * A kezdőpont csúcs adatait adja vissza
     * @return src
     */
    NodeData* getSrc() const{
        return this->src;
    }
    /**
     * A végpont csúcs adatait adja vissza
     * @return dst
     */
    NodeData* getDst() const{
        return this->dst;
    }
    /**
     * Az él típusát adja vissza
     * @return type
     */
    EdgeType getType() const{
        return this->type;
    }
    /**
     * Az él színét adja vissza
     * @return color
     */
    SDL_Color getColor() const{
        return this->color;
    }
};


#endif //HAZI_0328_EDGE_H
