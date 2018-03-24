#include <string>

#ifndef ADULTO_H
#define ADULTO_H

#include "Heroe.h"

using namespace std;

class Adulto : public Heroe{
    public:
        Adulto();
        Adulto(string , int , Item* , int , int );
        virtual void atacar(Monstruo*);
        virtual void atacarEspecial(Monstruo*);         
};

#endif