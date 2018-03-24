#include <string>
#include "Adulto.h"
#include "Jefe.h"
#include "SemiJefe.h"
#include "Comunes.h"

using namespace std;

Adulto::Adulto(){}

Adulto::Adulto(string nombre , int vida , Item* item , int jefesMatados , int dinero):Heroe( nombre ,  vida ,  item ,  jefesMatados , dinero){}

void Adulto::atacar(Monstruo* monstruo){
    Jefe* jefe = NULL;
    SemiJefe* semiJefe = NULL;
    Comunes* comunes = NULL;                               
    jefe = dynamic_cast<Jefe*>(monstruo);
    semiJefe = dynamic_cast<SemiJefe*>(monstruo);
    comunes = dynamic_cast<Comunes*>(monstruo);        

    if(jefe != NULL){     
        monstruo->setVida(monstruo->getVida()-8+2);                        
    }else{
        if(semiJefe != NULL){                                    
            monstruo->setVida(monstruo->getVida()-8+1);
        }else{            
            monstruo->setVida(monstruo->getVida()-8);
        }
    }
}


void Adulto::atacarEspecial(Monstruo* monstruo){
    Jefe* jefe = NULL;
    SemiJefe* semiJefe = NULL;
    Comunes* comunes = NULL;                               
    jefe = dynamic_cast<Jefe*>(monstruo);
    semiJefe = dynamic_cast<SemiJefe*>(monstruo);
    comunes = dynamic_cast<Comunes*>(monstruo);          

    if(jefe != NULL){     
        monstruo->setVida(monstruo->getVida()-12+2);                      
    }else{
        if(semiJefe != NULL){                        
            monstruo->setVida(monstruo->getVida()-12+1);
        }else{            
            monstruo->setVida(monstruo->getVida()-12);
        }
    }
}