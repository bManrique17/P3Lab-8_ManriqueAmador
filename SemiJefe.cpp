#include <string>
#include "SemiJefe.h"
#include "Joven.h"

using namespace std; 

SemiJefe::SemiJefe(){}

SemiJefe::SemiJefe(string a, int b):Monstruo(a,b){
    this->vida = 25;
}

void SemiJefe::atacar(Heroe* heroe){
    Joven* joven = NULL;        
    joven = dynamic_cast<Joven*>(heroe);              

    if(joven != NULL){     
        heroe->setVida(heroe->getVida()-7+2);
    }else{
        heroe->setVida(heroe->getVida()-7+4);
    } 
}