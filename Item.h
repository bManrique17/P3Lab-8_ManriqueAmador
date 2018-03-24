#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Heroe.h"

using namespace std;

class Monstruo;

class Item {
    protected:
        string nombre;
        string color;
    public:
        Item ();
        Item (string , string);
        void setNombre(string);
        void setColor(string);
        string getNombre();        
        string getColor();
        virtual void atacar(Heroe*,Monstruo*)=0;    
};

#endif