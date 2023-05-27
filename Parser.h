//
// Created by gombi on 2023.05.15..
//

#ifndef HAZI_0328_PARSER_H
#define HAZI_0328_PARSER_H

#include "texture_.h"
#include "stringList.h"
#include "config.h"

/**
 * A gmml leírónyelv feldolgozásáért felelős osztály.
 * A fájl sorait beolvasva feldolgozza majd létrehozza a megfelelő objektumokat
 */
class Parser {
    stringList *data;

public:
    /**
     * Alap konstruktor.
     * Létrehoz egy üres string listát.
     */
    Parser(){
        this->data = new stringList();
    }
    /**
     * Betölti és eltárolja a fájlból a sorokat
     */
    void Load();
    /**
     * Értelmezi az eltárolt sorokat és a létrehozott objektumokat egy heterogén kollekcióba helyezi, ahonnan azok ki lesznek rajzolva
     * @param textures heterogén kollekció
     * @param config konfig fájl, ami tárolja a színeket
     */
    void Parse(TextureList *textures, Config *config);
    /**
     * Destruktor.
     * Törli a string lista adatait majd magát az objektumot is törli
     */
    ~Parser(){
        this->data->clear();
        delete this->data;
    }
};


#endif //HAZI_0328_PARSER_H
