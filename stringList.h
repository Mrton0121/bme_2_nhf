//
// Created by gombi on 2023.05.24..
//

#ifndef HAZI_0328_STRINGLIST_H
#define HAZI_0328_STRINGLIST_H

#include <string>
using namespace std;

/**
 * Stringek tárolására alkalmas dinamikus tömbért felelős osztály.
 */
class stringList {
    int len;
    string **data;

public:
    /**
     * Alapértelmezett konstruktor.
     * Létrehoz egy 0 hosszúságú, üres listát.
     */
    stringList(){
        this->len = 0;
        this->data = nullptr;
    }
    /**
     * Elemek listához adásához használt függvény. Ha eddig üres lista volt, akkor létrehoz egy 1 hosszúságú listát.
     * Ha már volt benne elem, akkor növeli a hosszát és újra allokálja a listát a már új elemmel együtt.
     * @param element hozzáadandó elem
     */
    void push(string *element){
        if(this->len == 0){
            this->len = 1;
            this->data = new string*[1];
            this->data[0] = element;
        }
        else{
            this->len++;
            string** temp = this->data;
            this->data = new string*[this->len];
            for(int i = 0; i < this->len-1; i++){
                this->data[i] = temp[i];
            }
            this->data[this->len-1] = element;
            delete[] temp;
        }
    }

    /**
     * Visszaadja a dinamikusan foglalt string lista pointerét.
     * @return data
     */
    string** elements() {
        return this->data;
    };
    /**
     * Visszaadja a lista aktuális hosszát.
     * @return len
     */
    int length() const{
        return this->len;
    }

    /**
     * Felszabadítja a tömb összes elemét.
     */
    void clear(){
        for(int i = 0; i <this->length(); i++){
            delete this->elements()[i];
        }
    }

    /**
     * Alapértelmezett destruktor.
     * Felszabadítja a tömböt.
     */
    ~stringList(){
        delete[] this->data;
    }
};


#endif //HAZI_0328_STRINGLIST_H
