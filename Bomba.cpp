#include <string>
#include "Bomba.h"
#include "Jefe.h" 
#include "SemiJefe.h" 

using namespace std;

Bomba::Bomba(){}

Bomba::Bomba(string a, string b):Item(a,b){}

void Bomba::atacar(Heroe* heroe,Monstruo* monstruo){
    int defensa;
    Jefe* jefe = NULL;
    SemiJefe* semiJefe = NULL;
    
    jefe = dynamic_cast<Jefe*>(monstruo);
    semiJefe = dynamic_cast<SemiJefe*>(monstruo);
    
    if(jefe!=NULL){
        defensa = 2;
    }else{
        if(semiJefe!=NULL){
            defensa = 1;
        }else{
            defensa = 0;
        }
    }
    heroe->setVida(heroe->getVida()-4);
    if(monstruo->getDebilidad()==3){
        monstruo->setVida(monstruo->getVida()-20+defensa);    
    }else{
        monstruo->setVida(monstruo->getVida()-10+defensa);
    }    
    
}