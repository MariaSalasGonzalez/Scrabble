#ifndef Saco_h
#define Saco_h

#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <time.h>
#include <fstream>


using namespace std;

class Saco {
private:
	Ficha* fichas[100]; //un arreglo estatico a objetos fichas dinamicos 
	int numFichas;
public:
	Saco(); //de una vez se llena el arreglo 
	~Saco();

	int getNumFichas();
	void setNumFichas(int);
	void mostrarFichas();

	void eliminarFichas(Ficha*); //recibe una ficha, recorre el arreglo en busca de ese contenido y lo elimina (hace un corrimiento hacia la izquierda)

	Ficha *fichaRandom(); //genera una ficha del saco al azar (trabaja con objetos tipo <ficha>) y retorna el objeto en esa posicion

	void AgregarFicha(Ficha *); //recibe un puntero con una ficha 

}; //fin de la clase Saco
#endif // !Saco_h