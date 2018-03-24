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
#include <stdio.h>
#include <fstream>
#include <string.h>

using namespace std;

vector<Monstruo*> listaMonstruos;
Heroe* heroeActual;
void pelear();
void crearMonstruo();
void irTienda();
void guardarPartida();
void cargarPartida();
void borrarMonstruo();
void masterSword();
void usarItem();
//(string nombre , int vida , Item* item , int jefesMatados , int dinero )
struct HeroeBB{
    int vida;
    int jefesMatados;
    int dinero;
    char nombre[40];
};

int main(){
    int resp;
    cout<<"     **LAB8 Bryan Amador"<<endl;
    cout<<"(1)Crear nuevo Heroe"<<endl
        <<"(2)Cargar Heroe"<<endl
        <<"}->Ingrese su opcion"<<endl;
    int opcion;
    cin>>opcion;
    if(opcion==2){
        cargarPartida();
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
        <<"(6)Usar Master Sword"<<endl
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
                    cout<<"No hay mostruos"<<endl;
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
            case 6:
                masterSword();
                break;
        }

    }while(resp!=0);
    guardarPartida();
}

void pelear(){
    string nombre,color;
    int vidaActual = heroeActual->getVida();
    cout<<"     **PELEAR"<<endl;    
    
    
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
    int contPelea = 0;
    do{
        cout<<"\nPeleando con "<<listaMonstruos[indice]->getNombre()<<" -Vida: "<<listaMonstruos[indice]->getVida()<<endl;                
        cout<<""<<endl;
        cout<<"Vida del heroe: "<<heroeActual->getVida()<<endl
        <<"\n(1)Ataque especial"<<endl
        <<"(2)Ataque normal"<<endl
        <<"(3)Usar Item"<<endl
        <<"(4)Avandonar"<<endl
        <<"}->Ingrese el movimiento: ";        
        cin>>op;
        switch(op){
            case 1:            
                if(cont==0){                    
                    heroeActual->atacarEspecial(listaMonstruos[indice]);                    
                    cont=1;
                }else{
                    cout<<"__Ya has usado ataque especial :("<<endl;
                }
            break;
            case 2:                
                heroeActual->atacar(listaMonstruos[indice]);
            break;
            case 3:
                usarItem();
                heroeActual->getItem()->atacar(heroeActual,listaMonstruos[indice]);                
            break;
            case 4:                
                salida=true;
                cout<<"___Has abandonado .|."<<endl;
            break;
        }
        
        if(!salida){
            if(contPelea%2 == 0){
                cout<<"ATENCION! "<<listaMonstruos[indice]->getNombre()<<" te ha atacado!"<<endl;
                listaMonstruos[indice]->atacar(heroeActual);
            }else{
                cout<<"???? "<<listaMonstruos[indice]->getNombre()<<" ha decidio no atacarte :0"<<endl;
            }
        }
        contPelea++;
        if(heroeActual->getVida()<=0){
            cout<<"####### Heroe ha perdido, y tambien la mitad de su dinero -_-"<<endl;
            heroeActual->setDinero(heroeActual->getDinero()/2);
            break;
        }else{
            if(listaMonstruos[indice]->getVida()<=0){
                cout<<"&&&&&&& Heroe ha ganado"<<endl;
                Jefe* jefe=NULL;
                SemiJefe* semijefe=NULL;
                jefe = dynamic_cast<Jefe*>(listaMonstruos[indice]);
                semijefe = dynamic_cast<SemiJefe*>(listaMonstruos[indice]);
                heroeActual->setVida(vidaActual);
                if(jefe!=NULL){
                    heroeActual->setJefesMatados(heroeActual->getJefesMatados()+1);
                    heroeActual->setVida(heroeActual->getVida()+4);
                }else{
                    if(semijefe!=NULL){
                        heroeActual->setDinero(heroeActual->getDinero()+100);
                    }else{
                        heroeActual->setDinero(heroeActual->getDinero()+40);
                    }
                }
                break;
            }else{

            }
        }
    }while(op!=4 && !salida);
    
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

void masterSword(){
    cout<<"     **Master Sword"<<endl;
    Joven* joven = NULL;
    joven = dynamic_cast<Joven*>(heroeActual);
    if(joven != NULL){
        cout<<" "<<heroeActual->getNombre()<<" es un joven"<<endl;
        if(heroeActual->getJefesMatados() < 3){
            cout<<"Solo has matado "<<heroeActual->getJefesMatados()<<" jefes, necesitas 3"<<endl;
        }else{
            cout<<" FELICIDADES! "<<heroeActual->getNombre()<<" ya es adulto :D"<<endl;
            string nombre = heroeActual->getNombre();
            int vida = heroeActual->getVida();; 
            int jefesMatados = heroeActual->getJefesMatados();;
            int dinero = heroeActual->getDinero();;
            delete heroeActual;
            heroeActual = NULL;
            heroeActual = new Adulto(nombre,vida,NULL,jefesMatados,dinero);            
        }
    }else{
        char resp;
        cout<<" "<<heroeActual->getNombre()<<" es un adulto"<<endl;
        cout<<"->Desea guardar su Master Sword? (S/N)"<<endl;
        cin>>resp;
        if(resp=='s' || resp=='S'){
            cout<<" JUVENTUD! "<<heroeActual->getNombre()<<" es joven de nuevo :D"<<endl;
            string nombre = heroeActual->getNombre();
            int vida = heroeActual->getVida();; 
            int jefesMatados = heroeActual->getJefesMatados();;
            int dinero = heroeActual->getDinero();;
            delete heroeActual;
            heroeActual = NULL;
            heroeActual = new Joven(nombre,vida,NULL,jefesMatados,dinero);              
        }
    }
    
}




void usarItem(){
    string nombre,color;        
    cout<<"\n    Item"<<endl;

    cout<<"->Ingrese el color del item:";
    cin>>color;
    cout<<"->Ingrese el nombre del item:";
    cin>>nombre;

    cout<<"(1)Arco"<<endl
        <<"(2)Bumeran"<<endl
        <<"(3)Bomba"<<endl
        <<"]->Ingrese su nuevo Item: ";
    int indiceItem;
    cin>>indiceItem;        
    switch(indiceItem){
        case 1:{
            Item* temp = new Arco(nombre,color);
            heroeActual->setItem(temp);
        }break;
        case 2:{
            Item* temp = new Bumeran(nombre,color);
            heroeActual->setItem(temp);
        }break;
        case 3:{
            Item* temp = new Bomba(nombre,color);
            heroeActual->setItem(temp);
        }break;
    }
}

void guardarPartida(){  
    FILE* archivoHeroe = fopen("archivoHeroe.m17", "wb");

    HeroeBB heroeTemp;
    char nombreCC[40] ;
    strcpy( nombreCC, heroeActual->getNombre().c_str());

    strcpy(heroeTemp.nombre, nombreCC);    
    heroeTemp.vida = heroeActual->getVida();
    heroeTemp.dinero = heroeActual->getDinero();
    heroeTemp.jefesMatados = heroeActual->getJefesMatados();
    
    fwrite( &heroeTemp, sizeof(HeroeBB), 1, archivoHeroe );                
    fclose(archivoHeroe);
    cout<<heroeActual->getNombre()<<" ha sido guardado :3"<<endl;    
}

void cargarPartida(){
    FILE* archivoHeroe = fopen("archivoHeroe.m17", "rb");
    HeroeBB heroeTemp;
    fread ( &heroeTemp, sizeof(HeroeBB), 1, archivoHeroe );    
    heroeActual = new Joven(heroeTemp.nombre,heroeTemp.vida,NULL,heroeTemp.jefesMatados,heroeTemp.dinero);    
    fclose(archivoHeroe);    
    cout<<heroeActual->getNombre()<<" esta listo para pelear :3"<<endl;   
}