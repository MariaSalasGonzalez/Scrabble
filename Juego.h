#ifndef Juego_h
#define Juego_h
#include <iostream>
#include <Windows.h>
#include <string>
#include <time.h> 
using namespace std;
class Juego {
private:
	Diccionario *diccionario;
	Tablero *tablero;
	Saco *saco; //un puntero a un saco
	Jugador* jugadores; //para un arreglo dinamico a objetos estaticos
	int NumJugadores;

	int posicion; //para que funcione a todos y pueda cambiar
	int contador; //para las fichas del usuario
	bool primeraVez;//para cuando sea el primer turno de toda la partida
	bool exito; //para cuando se valide la palabra y salga
	
public:
	Juego();
	void jugadoresArray(); //para inicializar el arreglo

	void TurnosPlayers();

	void Jugar();

	void MenuJugador();

	void IngresarLetra(); //interctua con el jugador / tablero / diccionario
	void IngresarLetraPrimera(); //para el primer turno de toda la partida


}; //fin de la clase juego, donde se van a simular el juego

#endif // !Juego_h