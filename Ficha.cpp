#include "Ficha.h"

Ficha::Ficha(char letra, int puntos) {
	this->letra = letra;
	this->puntos = puntos;
} // fin del contructor con parametros

Ficha::Ficha() {
	letra = ' ';
	puntos = 0;
}// fin del contructor sin parametros

 /*Properties normales*/
char Ficha::getLetra() {
	return letra;
}
void Ficha::setLetra(char letra) {
	this->letra = letra;
}

int Ficha::getPuntos() {
	return this->puntos;
}
void Ficha::setPuntos(int puntos) {
	this->puntos = puntos;
}

void Ficha::mostrarLetra() {
	cout << "[" << getLetra() << "]";
}

void Ficha::mostrarPuntos() {
	cout << "[" << getPuntos() << "]";
}