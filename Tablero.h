#ifndef Tablero_h //si no esta definido el archivo Tablero_h que haga todo lo de abajo y defina el archivo
#define Tablero_h

#include <iostream>
#include <Windows.h> //para la funcion gotoxy
#include <sstream> //para el uso de variables stringstream
#include <string> 
#include <cstdlib> //para usar el free o delete en punteros
#include <fstream> //para la gestion de archivos

using namespace std;
class Tablero {
private:
	char matriz[15][15];
	char contenido[7]; //un arreglo de char porque 7 es el maximo de ltras que puede poner un jugador
	int devuelva = 0; 
	int fil[7]; //porque van a guardar datos
	int col[7];
public:
	Tablero(); //constructor
	string toString();
	void gotoxy(int, int);
	void Instrucciones(); //instrucciones del juego
	void setDevuelva(int); //para modificar la variable "devuelva"
	char getPosiciones(int, int);
	void insertar(int, int, char); //inserta ya la letra
	bool verificarFilaColumna(int, int);
	bool verificarFilaColumnaPrimeraVez(int, int);
	bool verificarFichaCentro(); //verifica que el centro este ocupado por alguna letra
	void guardarPosiciones(int, int);
	void devolverPosiciones();
	void ResetMatriz();
	bool VerificarCruz(int, int); //VERIFICA ARRIBA, ABAJO, IZQ Y DERE DE UNA LETRA

};//fin de la clase tablero
#endif // !Tablero_h //a partir de aqui ya la definicion de Tablero_h no existe 