#include<iostream>
using namespace std;

class NodoL{
	
	private:
		int tp, memo, tp2, id;
		string nombre;
	public:
		NodoL *siguiente;
		NodoL *Crear(string Nombre, int Pros, int Mem, int tie, int id){
			NodoL *nuevo = new NodoL();
			nuevo->nombre = Nombre;
			nuevo->tp = Pros;
			nuevo->memo = Mem;
			nuevo->tp2 = tie;
			nuevo->id = id;
		return nuevo;
		}
		
		int getTpros(){
			return tp;
		}

		
		string getNombre(){
			return nombre;
		}
		
		
		int getMemoria(){
			return memo;
		}
		
	
		int getTie2(){
			return tp2;
		}

		int getID() {
			return id;
		}

		void conectar(NodoL *next) { 
			siguiente = next;
		}
		
		void setTPros(int Tiempo){
			tp = Tiempo;
		}
		
		
		NodoL *obtieneSiguiente(){
			return siguiente;
		}

};
