

#include <string>
#include "Heroe.h"
#include "Item.h"

using namespace std;

Heroe::Heroe (){}

Heroe::Heroe (string nombre , int vida , Item* item , int jefesMatados , int dinero ){
        this->nombre = nombre;
        this->vida = vida;
        this->item = item;
        this->jefesMatados = jefesMatados;
        this->dinero = dinero;
}


void Heroe::setNombre( string nombre ){
    this->nombre = nombre;
}

void Heroe::setVida( int vida ){
    this->vida = vida;
}

void Heroe::setItem( Item* item ){
    this->item = item;
}

void Heroe::setJefesMatados( int jefesMatados ){
    this->jefesMatados = jefesMatados;
}

void Heroe::setDinero( int dinero ){
    this->dinero = dinero;
}


string Heroe::getNombre(){
    return nombre;
}

int Heroe::getVida(){
    return vida;
}

Item* Heroe::getItem(){
    return item;
}

int Heroe::getJefesMatados(){
    return jefesMatados;
}

int Heroe::getDinero(){
    return dinero;
}

void Heroe::atacar(Monstruo* m){

}

void Heroe::atacarEspecial(Monstruo* m){

}