#ifndef Diccionario_h
#define Diccionario_h

#include <iostream>
#include <string> 
#include <fstream>
using namespace std;
class Diccionario {
private:
	int contador = 0, id=0;
	ifstream diccionario;
	string palabras[189]; //para pasar mis palabras del diccionario al arreglo y asi es mas facil de buscar porque el mete 
	char palab[10];
public:
	Diccionario(); //constructor que abre el archivo Diccionario.dat
	void mostrarDiccionario(); //asi se ven las palabras del diccionario
	bool revisarPalabra(string); //ingresa una palabra y se verifica que exista

};//fin de la clase diccionario

#endif // !Diccionario_h