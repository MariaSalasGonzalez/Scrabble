#ifndef Jugador_h
#define Jugador_h
#include <iostream>
#include <fstream> //para la gestion de archivos
using namespace std;
class Jugador {
private:
	string nombre;
	Ficha* rack[7]; //el rack es donde tiene las 7 fichas, el rack es un arreglo que se va a llenar con las fichas aleatorias de una lista
	int cantidadRack;
	Ficha copiaRack[7]; //solo para tener almacenadas las letras
	int cantidadCopia;
	int puntaje;
	bool turno; 
	int pasar; //para que cuando se gane por pasar turnos, se lea este
	
public:
	Jugador();
	Jugador(string);

	string getNombre();
	void setNombre(string);

	int getPuntaje();
	void setPuntaje(int);

	bool getTurno();
	void setTurno(bool);


	void mostrarDatos(); //los datos y el rack del jugador

	void fillRack(Saco *); //recibe todo un objeto "saco" para llenar su propio arreglo con objetos "ficha" del "saco"
	
	string showPlayerRack();
	string mostrarCopia();

	bool verificarFichaAtril(char); //para que verifique que la letra digitada si existe en el rack
	
	int getPunto(char); //para retornar el punto de la letra
	void LlenarCopia(char, int); //recibe los objetos ficha del tablero del jugador
	void DevolverCopia(); //devuelve cuando 
	void mostrarFicha(Ficha *);
	
	void eliminarFichasRack(char); //recibe una ficha para poder hacer el corrimiento del rack del jugador

	~Jugador();

	void RellenarRack(Saco *); //ya funca

	void cambiarFichas(Saco *);//recibe lo que queda del saco

}; //fin de la clase jugador
#endif // !Jugador_h