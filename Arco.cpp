#include <string>
#include "Arco.h"
 

using namespace std;

Arco::Arco(){}

Arco::Arco(string a, string b):Item(a,b){}

void Arco::atacar(Heroe* heroe,Monstruo* monstruo){       
    if(monstruo->getDebilidad()==1){
        monstruo->setVida(monstruo->getVida()-8);    
    }else{
        monstruo->setVida(monstruo->getVida()-4);    
    }    
}