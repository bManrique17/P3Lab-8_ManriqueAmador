#ifndef HEROE_H
#define HEROE_H

#include <string>

using namespace std;

class Item;
class Monstruo;

class Heroe {
    private:
        string nombre;
        int vida;
        Item* item;
        int jefesMatados;
        int dinero;
    public:
        Heroe ();
        Heroe (string , int , Item* , int , int);        
        void setNombre(string);
        void setVida(int);
        void setItem(Item*);
        void setJefesMatados(int);
        void setDinero(int);
        string getNombre();
        int getVida();
        Item* getItem();
        int getJefesMatados();
        int getDinero();
        virtual void atacar(Monstruo*)=0;
        virtual void atacarEspecial(Monstruo*)=0;        
};

#endif
