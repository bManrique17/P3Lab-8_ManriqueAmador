#ifndef ARCO_H
#define ARCO_H
#include <string>                                                                                                                                                                                     
#include "Item.h"
#include "Heroe.h"
#include "Monstruo.h"

using namespace std;

class Arco : public Item{
    public:
        Arco();
        Arco(string , string);
        void atacar(Heroe*,Monstruo*);
};

#endif
