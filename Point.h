//
// Created by gombi on 2023.03.28..
//

#ifndef HAZI_0328_POINT_H
#define HAZI_0328_POINT_H

/**
 * Koordinátákat tárol, amiket a NodeData osztály használ fel.
 */
class Point {
public:
    int x;
    int y;
    /**
     * Konstruktorában alapértelmezettként a (0,0) pontot állítja be, a paraméterek egyenként felülírhatóak
     * @param x x koordináta
     * @param y y koordináta
     */
    Point(int x = 0, int y = 0){
        this->x = x;
        this->y = y;
    }
};


#endif //HAZI_0328_POINT_H
