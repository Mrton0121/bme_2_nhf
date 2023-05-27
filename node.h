//
// Created by gombi on 2023.03.28..
//

#ifndef HAZI_0328_NODE_H
#define HAZI_0328_NODE_H

#include "Point.h"
#include "string"
#include "SDL.h"
#include "stringList.h"

#include <iostream>

using namespace std;
/**
 * A csúcsok adatainak tárolására szolgál.
 * A térben való elhelyezkedésüket tárolja Point típussal és a színüket SDL_Color típussal
 */
class NodeData {
    Point coord;
    SDL_Color color;

public:
    string *id;
    /**
     * A NodeData osztály alapértelmezett konstruktora.
     * A string típusú 's' paraméterből feldarabolva létrehozza és eltárolja a szükséges értékeket
     * @param s bemeneti adatok a tetszőleges '.gmml' fájlokból
     * @param color a csúcs színe
     */
    NodeData(string s, SDL_Color color){
        string idt = s.substr(0, s.find(','));
        string x = s.substr(s.find(',')+1,s.find_last_of(','));
        string y = s.substr(s.find_last_of(',')+1,s.length());
        this->id = new string(idt);
        this->coord = Point(stoi(x),stoi(y));
        this->color = color;
    }

    /**
     * Visszaadja a térben való elhelyezkedését
     * @return coord
     */
    Point getCoord() const{
        return this->coord;
    }
    /**
     * Visszaadja az objektum egyedi azonosítóját
     * @return id
     */
    string *getId() const{
        return this->id;
    }
    /**
     * Visszaadja a csúcs színét
     * @return color
     */
    SDL_Color getColor() const{
        return this->color;
    }

};


#endif //HAZI_0328_NODE_H
