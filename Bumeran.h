#ifndef BUMERAN_H
#define BUMERAN_H
#include <string>                                                                                                                                                                                     
#include "Item.h"
#include "Heroe.h"
#include "Monstruo.h"

using namespace std;

class Bumeran : public Item{
    public:
        Bumeran();
        Bumeran(string , string);
        void atacar(Heroe*,Monstruo*);
};

#endif