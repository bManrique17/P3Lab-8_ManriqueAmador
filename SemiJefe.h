#ifndef SEMIJEFE_H
#define SEMIJEFE_H
#include <string>                                                                                                                                                                                     
#include "Heroe.h"
#include "Monstruo.h"

using namespace std;

class SemiJefe : public Monstruo{
    public:
        SemiJefe();
        SemiJefe(string , int);
        void atacar(Heroe*);
};

#endif