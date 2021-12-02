#include <iostream>
#include <windows.h>
#include<unistd.h>
#include "NodoL.h"
#include"ArbolBB.h"


using namespace std;

//NodoL*lista = NULL;
Nodo*arbol = NULL;
int memoria, t, t2, tiempopro, memo;
ArbolBB a;

class Lista{
	
	private:
		NodoL *inicio;
		
		bool esVacia(){
			if(inicio == NULL)
			return true;
		else
			return false;
		}
		
	public:
	void inicializar(){
			inicio=NULL;
			int memoria=0;			
	}

	void agregar(string Nombre, int tpros, int mem, int tie, int id){
			NodoL *nuevo, *aux;
			nuevo = nuevo ->Crear(Nombre,tpros,mem,tie,id);
			if(esVacia()){
				nuevo->siguiente=NULL;
				inicio=nuevo;
				nuevo=NULL;
			}else{
				aux=inicio;
				while(aux->obtieneSiguiente()!=NULL){
					aux=aux->obtieneSiguiente();
				}
				nuevo->siguiente=NULL;
				aux->conectar(nuevo);
				aux=NULL;
				nuevo=NULL;
			}
	}

	void mostrarLista(){
		int pos=70,pos2=15,pos3;
		NodoL *actual = new NodoL();
		actual = inicio;
		gotoxy(5,3);cout<<"Memoria: "<<memoria<<endl;
			
	
		while(actual != NULL){
			
			tiempopro=actual->getTpros();

			gotoxy(pos,pos2);cout << "Tarea: " << actual->getNombre().size() <<actual->getNombre()<< endl;
			gotoxy(pos,pos2+1);cout << "Porcentaje de memoria: " <<actual->getMemoria()<< endl;
			gotoxy(pos,pos2+2);cout << "Tiempo: "<<actual->getTie2()<<endl;
			gotoxy(pos,pos2+3);cout << "ID: "<<actual->getID()<<endl;
			gotoxy(pos,pos2+4);cout << "Tiempo para finalizar tarea: "<<tiempopro<<" minutos"<<endl;
			
			if(actual->getTie2()==tiempopro){
				memo=actual->getMemoria();
				memoria = memoria+memo;
				a.insertarNodo(arbol,actual->getTie2());
			}
				if(tiempopro==0){
					eliminar(inicio,actual->getID());
					memoria=memoria-memo;
				}
			
				t2=tiempopro-1;
                actual->setTPros(t2);
            	pos2=pos2+6;
				actual = actual->siguiente;		

	 }	

	}
	
	void desplegar(){ 
		NodoL *actual=new NodoL();;
		actual = inicio;
		while(actual != NULL){
				cout<<" "<<actual->getNombre()<<",";
				actual = actual->obtieneSiguiente(); 
		}
	}

	void eliminar(NodoL *&lista, int id){
		
		NodoL *aux_borrar;
		NodoL *anterior = NULL;
		aux_borrar = inicio;
		
		while((aux_borrar != NULL) && (aux_borrar->getID() != id)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		if(anterior==NULL){
			inicio=inicio->siguiente;
			delete aux_borrar;
		}else{
			anterior->siguiente=aux_borrar->siguiente;
			delete aux_borrar;
		}
		
	/*	if(inicio != NULL){
		NodoL *aux_borrar;
		NodoL *anterior = NULL;
		
		aux_borrar = inicio;
		
		while((aux_borrar != NULL)&&(aux_borrar->getID() != id)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		if(anterior == NULL){
			
			anterior->siguiente=aux_borrar->siguiente;
			delete aux_borrar;
			
		}
		else{
			
			inicio = inicio->siguiente;
			delete anterior;
			
		}*/
	}
		
	


	bool listaLlena() { 
        if (memoria>=8000)
        	
            return true;
        else
            return false;
    }

	int getMemoriaUsada() {
		return memoria;
	}
	
	void Desarbol(){
		a.verArbol(arbol,0);
	}
	
	void Orden(){
		a.inOrden(arbol);
	}
    
    void gotoxy(int x, int y){ 
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon,dwPos);
}
};
