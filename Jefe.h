#ifndef JEFE_H
#define JEFE_H
#include <string>                                                                                                                                                                                     
#include "Heroe.h"
#include "Monstruo.h"

using namespace std;

class Jefe : public Monstruo{
    public:
        Jefe();
        Jefe(string , int);
        void atacar(Heroe*);
};

#endif