#include <string>

#ifndef JOVEN_H
#define JOVEN_H
#include "Heroe.h"

using namespace std;

class Joven : public Heroe{
    public:
        Joven();
        Joven(string , int , Item* , int , int );
        virtual void atacar(Monstruo*);
        virtual void atacarEspecial(Monstruo*);         
};

#endif