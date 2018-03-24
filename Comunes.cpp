#include <string>
#include "Comunes.h"
#include "Joven.h"

using namespace std; 

Comunes::Comunes(){}

Comunes::Comunes(string a, int b):Monstruo(a,b){
    this->vida = 10;
}

void Comunes::atacar(Heroe* heroe){
    Joven* joven = NULL;        
    joven = dynamic_cast<Joven*>(heroe);              
    if(joven != NULL){     
        heroe->setVida(heroe->getVida()-5+2);
    }else{
        heroe->setVida(heroe->getVida()-5+4);
    } 
}