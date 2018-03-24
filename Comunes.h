#ifndef COMUNES_H
#define COMUNES_H
#include <string>                                                                                                                                                                                     
#include "Heroe.h"
#include "Monstruo.h"

using namespace std;

class Comunes : public Monstruo{
    public:
        Comunes();
        Comunes(string , int);
        void atacar(Heroe*);
};

#endif