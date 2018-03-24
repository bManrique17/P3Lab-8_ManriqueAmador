#include <string>
#include "Joven.h"
#include "Jefe.h"
#include "SemiJefe.h"
#include "Comunes.h"
#include <iostream>
using namespace std;

Joven::Joven(){}

Joven::Joven(string nombre , int vida , Item* item , int jefesMatados , int dinero):Heroe( nombre ,  vida ,  item ,  jefesMatados , dinero){}

void Joven::atacar(Monstruo* monstruo){
     
    Jefe* jefe = NULL;
    SemiJefe* semiJefe = NULL;
    Comunes* comunes = NULL;                               
    jefe = dynamic_cast<Jefe*>(monstruo);
    semiJefe = dynamic_cast<SemiJefe*>(monstruo);
    comunes = dynamic_cast<Comunes*>(monstruo);
    
    if(jefe != NULL){             
        monstruo->setVida(monstruo->getVida()-4+2);                                       
    }else{
        if(semiJefe != NULL){                                    
            monstruo->setVida(monstruo->getVida()-4+1);
        }else{            
            monstruo->setVida(monstruo->getVida()-4);            
        }
    }    
}


void Joven::atacarEspecial(Monstruo* monstruo){
    cout<<"|-|-|-|-|-Eres un joven, no puedes hacer ataque especial"<<endl;
}