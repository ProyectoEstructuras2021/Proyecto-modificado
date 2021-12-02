#include<iostream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<unistd.h>
#include"aux1.h"
#include"Lista.h"



#include<sstream>

using namespace std;


void gotoxy(int,int);
NodoL*lista = NULL;
int tiempo();
int esperando, cont, proceso, cont2, tie, pos=10, pos2=15, memori;
string name,name2,nam;
stringstream ss,sa;
Lista l;
aux1 aux;


int main(){
		system("color 80");
		system("mode con: cols=140 lines=40");
		tiempo();		
		return 0;
}

int tiempo(){
	l.inicializar();
	aux.inicializarArbol();
	p.inicializar();
	
for(int i=0; i<=10; i++){
		
	int longitud = strlen("TAREAS EN esperando");
	int ctext=31-(longitud/2);
	gotoxy(ctext,12);
	cout << "TAREAS EN ESPERANDO" <<endl;
	
	int longitud2 = strlen("TAREAS EN PROCESAMIENTO");
	int ctext2=100-(longitud2/2);
	gotoxy(ctext2,12);
	cout << "TAREAS EN PROCESAMIENTO" <<endl;
	
	int longitud3 = strlen("PROYECTO FINAL");
	int ctext3=70-(longitud3/2);
	gotoxy(ctext3,2);
	cout << "PROYECTO FINAL" <<endl;
	
	int longitud4 = strlen("MEMORIA DE PROCESAMIENTO");
	int ctext4=70-(longitud4/2);
	gotoxy(ctext4,5);
	cout << "MEMORIA DE PROCESAMIENTO" <<endl;
	
	int longitud6 = strlen("TIEMPO TOTAL DE PROCESAMIENTO:  minutos");
	int ctext6=135-(longitud6+3);
	gotoxy(ctext6,8);
	cout << "Tiempo total de procesamiento: "<<i<<" minutos"<<endl;
	
	
	for(int i=5; i<135; i++){
			gotoxy(i,10);cout<<"_";	
	}
	for(int i=5; i<135; i++){
			gotoxy(i,13);cout<<"_";	
	}
	for(int i=11; i<14; i++){
			gotoxy(65,i);cout<<"|";	
	}
	for(int i=11; i<14; i++){
			gotoxy(4,i);cout<<"|";	
	}
	for(int i=11; i<14; i++){
			gotoxy(135,i);cout<<"|";	
	}	
	for(int i=11; i<40; i++){
			gotoxy(135,i);cout<<"|";	
	}	
	for(int i=11; i<40; i++){
			gotoxy(4,i);cout<<"|";	
	}
	for(int i=11; i<40; i++){
			gotoxy(65,i);cout<<"|";	
	}

			if(esperando==0){
				esperando=aux.espera();
				name2=aux.nombre();
			}else{
				esperando--;
			}
		
	int longitud5 = strlen("La siguiente tarea se creara en: ");
	int ctext5=70-(longitud5/2);
	gotoxy(5,8);
	cout << "La siguiente tarea se creara en: " <<esperando<<endl;
		
		
		if(l.getMemoriaUsada() + aux.memoria() < 8192){
			nam=p.pop();
			proceso=aux.atencion();//array tproceso
			memori=aux.memoria();//array memoria
			tie=proceso;
			cont2++;
			l.agregar(nam,proceso,memori,tie,cont2);
		
		}else{ //COLA
			if(l.getMemoriaUsada() >= 8000){
				
				system("Color A4");gotoxy(2,4);cout<<l.getMemoriaUsada();
				cont++;
			}
			
			gotoxy(pos,14);cout<<"\n"<<endl;
			aux.mostrar(0);

		}
			l.mostrarLista();
	
		

		sleep(1);
	
	system("cls");		

}
	system("Color 90");
	cout << " - - - - - - > R E P O R T E  F I N A L < - - - - - -" << endl;
	cout << " > Tareas que se quedaron en Cola de Espera:\n" << endl;
	p.mostrarCola();
	cout << "\n\n\n > Tareas que se quedaron en Lista de Procesamiento:\n" << endl;
	l.desplegar();
	cout << " \n\n\n> Veces que se llego al tope de procesamiento de la memoria RAM:" <<cont<< endl;
	
	cout << "\n\n\n > Arbol de Tareas atendidas: \n" << endl;
	
	l.Desarbol();
	
	cout << " \n\n\n> Tareas del Arbol (inorden)\n" << endl;
	
	l.Orden();


}

void gotoxy(int x, int y){
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon,dwPos);
}

