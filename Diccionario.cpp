#include "Diccionario.h"
Diccionario::Diccionario() {
	diccionario.open("Diccionario.dat", ios::in | ios::binary);
	diccionario >> palab;
	int cont = 1; // para verificar el id de las palabras
	while (!diccionario.eof()) {
		diccionario >> id; //hace una lectura del id de la letra
		if (id == cont) {
			palabras[contador] = palab;
		}
		diccionario >> palab;
		contador++;
		cont++;
	}//fin del while
	diccionario.close();
} //fin del constructor de diccionario

void Diccionario::mostrarDiccionario() {
	for (int i = 0; i < contador; i++) {
		cout << palabras[i] << endl;
	}
}

bool Diccionario::revisarPalabra(string palab) {
	for (int i = 0; i < contador; i++) {
		if (palabras[i] == palab) {
			return true;
		}
	}
	return false;
}