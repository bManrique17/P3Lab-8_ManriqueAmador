
#include "Item.h"
#include <string>

using namespace std;

Item::Item (){}

Item::Item (string nombre , string color ){
        this->nombre = nombre;
        this->color = color;
}

void Item::setNombre( string nombre ){
    this->nombre = nombre;
}

void Item::setColor( string color ){
    this->color = color;
}


string Item::getNombre(){
    return nombre;
}

string Item::getColor(){
    return color;
}

void Item::atacar(Heroe* heroe,Monstruo* Monstruo){

}
