#include  <iostream>
#include "Nodo.h"
#include <string>
#include <sstream>

using namespace std;

class ArbolBB{
	
private:
		
	Nodo *raiz;
		
    string NodosHermanos;
	string NodosPadres;
	string NodosHijos;
	string NodosHojas;
		
		bool arbolVacio(){
			if(raiz == NULL)
				return true;
			else 
				return false;
		}	
	
public:

	void inicializarArbol(){
			raiz = NULL;
		}

	void insertarNodo(Nodo *&arbol, int n){
		if(arbol==NULL){
			Nodo *nuevo; 
			nuevo = nuevo->Crear(n);
			arbol=nuevo;
		}
		else{
			int raiz = arbol->dato;
		if(n<raiz){
			insertarNodo(arbol->izq,n);
		}
		else{
			insertarNodo(arbol->der,n);
		}
		}
	}
	
	void verArbol(Nodo *arbol, int n){
		
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<<arbol->dato<<endl;

     verArbol(arbol->izq, n+1);
	}
	
	void inOrden(Nodo *arbol){
		cout<<"  ";
		if(arbol==NULL){
			return;
		}
		else{
			inOrden(arbol->izq);
			cout<<arbol->dato<<" - ";
			inOrden(arbol->der);
		}
	}
		
};
