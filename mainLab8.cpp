#include <string>
#include "Item.h"
#include "Monstruo.h"
#include "Heroe.h"
#include "Bomba.h"
#include "Bumeran.h"
#include "Arco.h"
#include "Jefe.h"
#include "SemiJefe.h"
#include "Comunes.h"
#include "Joven.h"
#include "Adulto.h"
#include <vector>
#include <iostream>

using namespace std;

vector<Monstruo*> listaMonstruos;
Heroe* heroeActual;
void pelear();
void crearMonstruo();
void irTienda();
void guardarPartida();
Heroe* cargarPartida();
void borrarMonstruo();

int main(){
    int resp;
    cout<<"     **LAB8 Bryan Amador"<<endl;
    cout<<"(1)Crear nuevo Heroe"<<endl
        <<"(2)Cargar Heroe"<<endl
        <<"}->Ingrese su opcion"<<endl;
    int opcion;
    cin>>opcion;
    if(opcion==2){
        heroeActual = cargarPartida();
    }else{
        string nombre;
        int dinero;        
        cout<<" **Crear heroe"<<endl;
        cout<<"->Ingrese el nombre del Heroe: ";
        cin>>nombre;
        cout<<"->Ingrese el dinero: ";
        cin>>dinero;
        //string nombre , int vida , Item* item , int jefesMatados , int dinero ){
        heroeActual = new Joven(nombre,12,NULL,0,dinero);
        cout<<"___Heroe creado"<<endl;
    }
    do{
        cout<<"     **LAB8 Bryan Amador"<<endl
        <<"(1)Ir a tienda"<<endl
        <<"(2)Pelear"<<endl
        <<"(3)Crear monstruo"<<endl
        <<"(4)Borrar monstruo"<<endl
        <<"(5)Guardar partida"<<endl
        <<"(0)Salir"<<endl
        <<"->Ingrese su opcion: ";
        cin>>resp;
        switch(resp){
            case 0:
            break;
            case 1:
                irTienda();
            break;
            case 2:
                if(listaMonstruos.size()<1){
                    cout<<"No har mostruos"<<endl;
                }else{
                    pelear();
                }                
            break;
            case 3:
                crearMonstruo();
            break;
            case 4:
                borrarMonstruo();
            break;
            case 5:
                guardarPartida();
            break;
        }

    }while(resp!=0);
}

void pelear(){
    string nombre,color;
    cout<<"     **PELEAR"<<endl;
    cout<<"--->Item"<<endl
        <<"(1)Arco"<<endl
        <<"(2)Bumeran"<<endl
        <<"(3)Bomba"<<endl
        <<"}->Ingrese el Item: ";
    int tipo;
    cin>>tipo;
    cout<<"->Ingrese el color:";
    cin>>color;
    cout<<"->Ingrese el nombre:";
    cin>>nombre;
    if(tipo==1){
        Item* temp = new Arco(nombre,color);
        heroeActual->setItem(temp);
    }else{
        if(tipo==2){
            Item* temp = new Bumeran(nombre,color);
            heroeActual->setItem(temp);
        }else{
            Item* temp = new Bomba(nombre,color);
            heroeActual->setItem(temp);
        }
    }
    int indice;
    cout<<"    **Monstruo a escoger"<<endl;
    for(int i=0 ; i<listaMonstruos.size() ; i++){
        cout<<"     "<<(i+1)<<" - "<<listaMonstruos[i]->getNombre()<<endl;
    }
    cout<<"->Ingrese el numero a retar: ";    
    cin>>indice;
    indice--;
    bool salida = false;
    int cont = 0;
    int op;
    do{
        cout<<"Peleando con "<<listaMonstruos[indice]->getNombre()<<" -Vida: "<<listaMonstruos[indice]->getVida()<<endl;        
        cout<<""<<endl;
        cout<<"Vida del heroe: "<<heroeActual->getVida()<<endl
        <<"\n(1)Ataque normal"<<endl
        <<"(2)Ataque especial"<<endl
        <<"(3)Avandonar"<<endl
        <<"}->Ingrese el movimiento: ";        
        cin>>op;
        switch(op){
            case 1:
            break;
                if(cont==0){
                    heroeActual->atacarEspecial(listaMonstruos[indice]);
                    cont=1;
                }else{
                    cout<<"__Ya has usado ataque especial .("<<endl;
                }
            case 2:
                heroeActual->atacar(listaMonstruos[indice]);
            break;
            case 3:                
                salida=true;
                cout<<"___Has abandonado .l."<<endl;
            break;
        }
        cout<<"\n    Item"<<endl;
        cout<<"(1)Arco"<<endl
            <<"(2)Bumeran"<<endl
            <<"(3)Bomba"<<endl
            <<"]->Ingrese su nuevo Item: ";
        int indiceItem;
        cin>>indiceItem;
        switch(indiceItem){
            case 1:{
                Item* temp = new Arco(heroeActual->getItem()->getNombre(),heroeActual->getItem()->getColor());
                heroeActual->setItem(temp);
            }break;
            case 2:{
                Item* temp = new Bumeran(heroeActual->getItem()->getNombre(),heroeActual->getItem()->getColor());
                heroeActual->setItem(temp);
            }break;
            case 3:{
                Item* temp = new Bomba(heroeActual->getItem()->getNombre(),heroeActual->getItem()->getColor());
                heroeActual->setItem(temp);
            }break;
        }

        if(heroeActual->getVida()<=0){
            cout<<"Heroe ha perdido"<<endl;
            break;
        }else{
            if(listaMonstruos[indice]->getVida()<=0){
                cout<<"Heroe ha ganado"<<endl;
                break;
            }else{

            }
        }
    }while(op!=3 && !salida);

}

void crearMonstruo(){
    string nombre;
    cout<<"   **Crear Monstruo"<<endl;
    cout<<"]->Ingrese el nombre: ";
    cin>>nombre;
    cout<<"(1)Jefe"<<endl
        <<"(2)SemiJefe"<<endl
        <<"(3)Comun"<<endl
        <<"]->Ingrese el tipo de monstruo a crear: ";
    int tipo;
    cin>>tipo;
    cout<<"--->Debilidad"<<endl
        <<"(1)Arco"<<endl
        <<"(2)Bumeran"<<endl
        <<"(3)Bomba"<<endl
        <<"}->Ingrese la debilidad: ";
    int debilidad;
    cin>>debilidad;
    if(tipo==1){        
        Monstruo* temp = new Jefe(nombre,debilidad);
        listaMonstruos.push_back(temp);
    }else{
        if(tipo==2){
            Monstruo* temp = new SemiJefe(nombre,debilidad);
            listaMonstruos.push_back(temp);
        }else{
            Monstruo* temp = new Comunes(nombre,debilidad);
            listaMonstruos.push_back(temp);
        }
    }
    
    cout<<"___Creado"<<endl;
}

void irTienda(){
    cout<<"   **TIENDA"<<endl;
    if(heroeActual->getDinero()<200){
        cout<<"No hay suficiente dinero para comprar"<<endl;
    }else{
        cout<<"Corazon comprado :)"<<endl;
        heroeActual->setVida(heroeActual->getVida() + 4);
        heroeActual->setDinero(heroeActual->getDinero() - 200);
    }
}

void guardarPartida(){

}

Heroe* cargarPartida(){

}

void borrarMonstruo(){
    cout<<"    **BORRAR MONSTRUO"<<endl;
    for(int i=0 ; i<listaMonstruos.size() ; i++){
        cout<<"     "<<(i+1)<<" - "<<listaMonstruos[i]->getNombre()<<endl;
    }
    cout<<"->Ingrese el numero a eliminar: ";
    int indice;
    cin>>indice;
    indice--;
    if(indice<0 || indice>listaMonstruos.size()-1){
		cout<<"X Invalido"<<endl;
	}else{
		cout<<"ELIMINADO"<<endl;
		listaMonstruos.erase(listaMonstruos.begin()+indice,listaMonstruos.begin()+(indice+1));
	}
}
