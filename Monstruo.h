#ifndef MONSTRUO_H
#define MONSTRUO_H

#include <string>
#include "Heroe.h"

using namespace std;

class Monstruo{
    public:
        Monstruo ();
        Monstruo (string,int);
        void setNombre(string);
        void setDebilidad(int);
        void setVida(int);
        int getVida();
        string getNombre();
        int getDebilidad();
        virtual void atacar(Heroe*)=0;
    protected:
        string nombre;
        int debilidad;
        int vida;
};

#endif