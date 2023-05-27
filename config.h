//
// Created by gombi on 2023.05.25..
//

#ifndef HAZI_0328_CONFIG_H
#define HAZI_0328_CONFIG_H

#include "SDL.h"

/**
 * A konfigurációs fájl betöltéséért és feldolgozásáért felelős osztály, ami eltárolja a
 * csúcsok, élek és háttér színeit
 */
class Config {
    SDL_Color nodeColor;
    SDL_Color edgeColor;
    SDL_Color backgroundColor;

public:
    /**
     * A konstruktor a megadott elérési út alapján beolvassa és eltárolja a megadott RGB színeket
     * @param path
     */
    Config(const char* path);
    /**
     * Visszaad egy SDL_Color típusú értéket, ami a csúcsok színét tárolja
     * @return nodeColor
     */
    const SDL_Color getNodeC() { return this->nodeColor; }
    /**
     * Visszaad egy SDL_Color típusú értéket, ami az élek színét tárolja
     * @return nodeColor
     */
    const SDL_Color getEdgeC() { return this->edgeColor; }
    /**
     * Visszaad egy SDL_Color típusú értéket, ami a háttér színét tárolja
     * @return nodeColor
     */
    const SDL_Color getBackgC() { return this->backgroundColor; }
};


#endif //HAZI_0328_CONFIG_H
