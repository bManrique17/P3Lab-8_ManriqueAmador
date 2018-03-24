#include <string>
#include "Jefe.h"
#include "Joven.h"

using namespace std; 

Jefe::Jefe(){}

Jefe::Jefe(string a, int b):Monstruo(a,b){
    this->vida = 35;
}

void Jefe::atacar(Heroe* heroe){
    Joven* joven = NULL;        
    joven = dynamic_cast<Joven*>(heroe);              

    if(joven != NULL){     
        heroe->setVida(heroe->getVida()-9+2);
    }else{
        heroe->setVida(heroe->getVida()-9+4);
    } 
}