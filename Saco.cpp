#include "Ficha.h"
#include "Saco.h"

Saco::Saco() {
	this->numFichas = 0;
	const char letras[] = { '*','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	const int  cantidad[] = { 2,9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1 };
	const int puntos[] = { 0,1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10 };
	for (int i = 0; i < 27; i++) { //la cantidad de letras que hay
		for (int j = 0; j < cantidad[i]; j++) { //la cantidad de cada letra que hay 
			fichas[numFichas] = new Ficha(letras[i], puntos[i]);
			numFichas++;
		}
	}
}

Saco::~Saco() {
	for (int i = 0; i<100; i++)
		delete fichas[i];
}

int Saco::getNumFichas() {
	return this->numFichas;	}

void Saco::setNumFichas(int numFichas) {
	this->numFichas = numFichas;	}

void Saco::mostrarFichas() { //muetra las fichas y el puntaje
	for (int i = 0; i < getNumFichas(); i++) {
		fichas[i]->mostrarLetra();
		fichas[i]->mostrarPuntos();
		cout << "\t";
	}
}

Ficha *Saco::fichaRandom() { //pues lo que retona son los objetos ficha
	srand(time(NULL)); //semilla
	int ficha;
	ficha = (rand() % getNumFichas()); //genera un numero random de 0 a la cantidad de fichas disponibles
	return fichas[ficha]; //y retorna el objeto ficha en esa posicion
}

void Saco::eliminarFichas(Ficha* ficha) { //recibe toda una ficha completa 
	for (int i = 0; i < numFichas; i++) { //para recorrer el arreglo 
		if (fichas[i]->getLetra() == ficha->getLetra()) { //como el contenido del arreglo es dinamico, se obtiene la ficha para compararla
			for (int j = i; j < numFichas - 1; j++) { //hasta numFichas-1 para que no traiga basura al ultimo lugar
				fichas[j]->setLetra(fichas[j + 1]->getLetra());
				fichas[j]->setPuntos(fichas[j + 1]->getPuntos());
			}
			numFichas--;
			break;
		} //fin del if
	}//fin del for de i
}//fin de eliminar ficha

void Saco::AgregarFicha(Ficha *temp) { 
	fichas[numFichas] = temp; //asigna en la ultima casilla disponible
	numFichas++;
}//fin del metodo ficha
