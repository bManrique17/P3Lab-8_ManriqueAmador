#include <string>
#include "Joven.h"
#include "Jefe.h"
#include "SemiJefe.h"
#include "Comunes.h"

using namespace std;

Joven::Joven(){}

Joven::Joven(string nombre , int vida , Item* item , int jefesMatados , int dinero):Heroe( nombre ,  vida ,  item ,  jefesMatados , dinero){}

void Joven::atacar(Monstruo* monstruo){
    int poderItem;    
    Monstruo* jefe = NULL;
    Monstruo* semiJefe = NULL;
    Monstruo* comunes = NULL;                               
    jefe = dynamic_cast<Jefe*>(monstruo);
    semiJefe = dynamic_cast<SemiJefe*>(monstruo);
    comunes = dynamic_cast<Comunes*>(monstruo);

    if(jefe != NULL){
        monstruo->setVida(monstruo->getVida()-4+2);
        //item->atacar(this,monstruo);
        if(monstruo->getVida()<=0){
            jefesMatados++;
            vida++;
        }        
    }else{
        if(semiJefe != NULL){
            monstruo->setVida(monstruo->getVida()-4+1);
        }else{
            monstruo->setVida(monstruo->getVida()-4);
        }
    }
}


void Joven::atacarEspecial(Monstruo* monstruo){


}