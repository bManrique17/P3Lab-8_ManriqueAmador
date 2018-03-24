#ifndef BOMBA_H
#define BOMBA_H
#include <string>                                                                                                                                                                                     
#include "Item.h"
#include "Heroe.h"
#include "Monstruo.h"

using namespace std;

class Bomba : public Item{
    public:
        Bomba();
        Bomba(string , string);
        void atacar(Heroe*,Monstruo*);
};

#endif