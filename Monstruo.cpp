
#include "Monstruo.h"
#include <string>

Monstruo::Monstruo (){}

Monstruo::Monstruo (string nombre , int debilidad ){
        this->nombre = nombre;
        this->debilidad = debilidad;
}

void Monstruo::setNombre( string nombre ){
    this->nombre = nombre;
}

void Monstruo::setDebilidad( int debilidad ){
    this->debilidad = debilidad;
}


string Monstruo::getNombre(){
    return nombre;
}

int Monstruo::getDebilidad(){
    return debilidad;
}

void Monstruo::atacar(Heroe* heroe){

}