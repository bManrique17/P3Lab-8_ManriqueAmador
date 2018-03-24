#include <string>
#include "Joven.h"

using namespace std;

Joven::Joven(){}

Joven::Joven(string nombre , int vida , Item* item , int jefesMatados , int dinero):Heroe( nombre ,  vida ,  item ,  jefesMatados , dinero){}

void Joven::atacar(Monstruo* monstruo){

}


void Joven::atacarEspecial(Monstruo* monstruo){


}