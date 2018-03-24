#include <string>
#include "Jefe.h"

using namespace std; 

Jefe::Jefe(){}

Jefe::Jefe(string a, int b):Monstruo(a,b){
    this->vida = 35;
}

void Jefe::atacar(Heroe*){

}