#include <string>
#include "Bumeran.h"
#include "Jefe.h" 
#include "SemiJefe.h" 

using namespace std;

Bumeran::Bumeran(){}

Bumeran::Bumeran(string a, string b):Item(a,b){}

void Bumeran::atacar(Heroe* heroe,Monstruo* monstruo){
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
    if(monstruo->getDebilidad()==2){
        monstruo->setVida(monstruo->getVida()-10+defensa);    
    }else{
        monstruo->setVida(monstruo->getVida()-5+defensa);
    }
    
}