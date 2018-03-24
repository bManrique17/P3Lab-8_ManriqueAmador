#include <string>
#include "Bomba.h"

using namespace std;

Bomba::Bomba(){}

Bomba::Bomba(string a, string b):Item(a,b){}

void Bomba::atacar(Heroe* heroe,Monstruo* monstruo){
    heroe->setVida(heroe->getVida()-4);
    monstruo->setVida(monstruo->getVida()-10);
}