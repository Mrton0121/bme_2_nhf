//
// Created by gombi on 2023.04.17..
//

#ifndef HAZI_0328_GRAFIKA_H
#define HAZI_0328_GRAFIKA_H

#include "SDL.h"

/**
 * Az SDL grafikai feldolgozó műveleteit kezeli
 */
class Grafika {
    SDL_Window* window;

public:
    SDL_Renderer* renderer;
    /**
     * A konstruktor létrehozza a megadott értékekkel az ablakot és beállítja a renderer publikus változó értékét
     * @param title az ablak címe
     * @param x az ablak szélessége
     * @param y az ablak magassága
     * @param backgroundColor az ablak háttérszíne
     */
    Grafika(const char* title, int x, int y, SDL_Color backgroundColor);
    /**
     * Addig tartja nyitva az ablakot, amíg a felhasználó nem zárja be vagy nyom meg egy gombot.
     * Ezt az SDL beépített event-kezelőjével valósítja meg.
     */
    static void await();
    /**
     * A háttérszín átállítására szolgáló függvény
     * @param color a kívánt szín
     */
    void setBackgroundColor(SDL_Color color) const;
    /**
     * Destruktor, ami megsemmisíti az SDL által létrehozott objektumokat.
     */
    ~Grafika();
};



#endif //HAZI_0328_GRAFIKA_H
