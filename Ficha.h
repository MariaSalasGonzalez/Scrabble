#ifndef Ficha_h
#define Ficha_h

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Ficha { //en vez de nodo se llama ficha
private:
	char letra;
	int puntos; //puntaje de la letra
public:
	/*Constructor*/
	Ficha(char, int); //letra, valor
	Ficha();

	/*Properties normales*/
	char getLetra();
	void setLetra(char);

	int getPuntos();
	void setPuntos(int);

	void mostrarLetra();
	void mostrarPuntos();


};//fin de la clase letra

#endif // !Ficha_h
