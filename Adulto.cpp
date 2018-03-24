#include <string>
#include "Adulto.h"

using namespace std;

Adulto::Adulto(){}

Adulto::Adulto(string nombre , int vida , Item* item , int jefesMatados , int dinero):Heroe( nombre ,  vida ,  item ,  jefesMatados , dinero){}

void Adulto::atacar(Monstruo* monstruo){

}


void Adulto::atacarEspecial(Monstruo* monstruo){


}