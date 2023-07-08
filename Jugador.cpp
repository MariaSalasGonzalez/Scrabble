#include "Ficha.h"
#include "Saco.h"
#include "Jugador.h"

Jugador::Jugador() {
	nombre = "";
	puntaje = 0;
	cantidadRack = 0;
	cantidadCopia = 0;
	turno = false; 
	pasar = 0; //
} //fin del constructor SIN param

Jugador::Jugador(string nombre) {
	this->nombre = nombre;
	puntaje = 0;
	cantidadRack = 0;
	cantidadCopia = 0;
	turno = false;
	pasar = 0;
}//fin del constructor con param

string Jugador::getNombre() {
	return this->nombre;	}

void Jugador::setNombre(string nombre) {
	this->nombre = nombre;	}

int Jugador::getPuntaje() {
	return this->puntaje;	}
void Jugador::setPuntaje(int puntaje) {
	this->puntaje = puntaje;	}

bool Jugador::getTurno() {
	return turno;	}
void Jugador::setTurno(bool turn) {
	turno = turn;	}


void Jugador::mostrarDatos() { //para mostrar los datos y el rack del jugador
	cout << "Nombre: " << getNombre() << endl;
	cout << "Puntaje: " << getPuntaje() << endl;
	for (int i = 0; i < cantidadRack; i++) { //que muestre solo las que tenga en cantidad
		rack[i]->mostrarLetra();
		rack[i]->mostrarPuntos();
		cout << endl;
	}
}

string Jugador::showPlayerRack() {
	stringstream r;
	for (int i = 0; i < cantidadRack; i++) {
			rack[i]->mostrarLetra();
			rack[i]->mostrarPuntos();
			cout << endl;
	} //fin del for i
	return r.str();
}//para que solo muestre el atril

string Jugador::mostrarCopia() {
	stringstream c;
	for (int i = 0; i < cantidadCopia; i++) {
		copiaRack[i].mostrarLetra();
		copiaRack[i].mostrarPuntos();
		cout << endl;
	}
	return c.str();
} //fin de mostrar la copia del rack

void Jugador::mostrarFicha(Ficha *ficha) {
	cout << endl << ficha->getLetra() << " ";
	cout << ficha->getPuntos() << endl << endl;
}

void Jugador::fillRack(Saco *saco) { //para llenar el rack del jugador con objetos del saco (que son tipo ficha)// con un puntero a Saco se puede llamar a metodos del saco
	for (int i = cantidadRack; i < 7; i++) { //porque cantidad r
		rack[i] = saco->fichaRandom(); //saco llama al fichaRandom() y asigna lo que retorna al rack
		cantidadRack++;
		saco->eliminarFichas(rack[i]); //le manda una la ficha que recibio
	}
}//fin de llenar el atril del jugador

Jugador::~Jugador() { //destuctor
	for (int i = 0; i > 100; i++)
		delete rack[i];
}

bool Jugador::verificarFichaAtril(char letra) { //verifica que exista la letra en el atril del jugador
	for (int i = 0; i < cantidadRack; i++) {
		if (letra == rack[i]->getLetra()) {
			return true;
		}//fin del if
	} //fin del for 
	return false; //si al final revisa y no son iguales, retorn falso
}//fin del metodo verificarFichaAtril

void Jugador::eliminarFichasRack(char letter) {
	for (int i = 0; i < 7; i++) {  //recorre hasta la cantidad de fichas que tiene el rack
		if (rack[i]->getLetra() == letter) {//si las letras son iguales
			rack[i]->setLetra(' '); //va a ser un espacio
			rack[i]->setPuntos(0);
			break;
		}//fin del if para verificar
	}//fin del for que recorre el arreglo // fin del for i
}//fin del metodo eliminar

int Jugador::getPunto(char letter){
	for (int i = 0; i < 7; i++) {
		if (rack[i]->getLetra() == letter)
			return rack[i]->getPuntos(); //retorna el puntaje de una letra
	}
}//fin del getPunto

void Jugador::LlenarCopia(char letter, int num) { //llenar el arreglo 
	copiaRack[cantidadCopia].setLetra(letter);
	copiaRack[cantidadCopia].setPuntos(num);
	cantidadCopia++;
}//fin de llenar copia

void Jugador::DevolverCopia() { //asi devuelve las letras
	int cont = 0;
	for (int i = 0; i < 7; i++) { //recorre el rack del jugador
		if (rack[i]->getLetra() == ' ') {//si hay un campo en vacio
			rack[i]->setLetra(copiaRack[cont].getLetra());
			rack[i]->setPuntos(copiaRack[cont].getPuntos());
			cont++;
		}//fin del if
	}//fin del for del rack jugador
	cantidadCopia = 0; //asi se le cae encima al primer 
}//fin del devolverCopia

void Jugador::RellenarRack(Saco *saco) { //siempre reciben el saco ACTUALIZADO
	for (int i = 0; i < 7; i++) {//recorrer el rack jugador
		if (rack[i]->getLetra() == ' ') {
			rack[i] = saco->fichaRandom();
			saco->eliminarFichas(rack[i]);
		} //sin el break para rellenar todos los espacios en blanco 
	}//for i
}//fin del  Rellenar

void Jugador::cambiarFichas(Saco *saco) { //recibe el saco ACTUALIZADO
	char letra;
	int op = 0;
	int cont = 0; //un contador para estar cambiando las fichas, solo puede hacer 7 cambios de fichas
	do {
		cout << "Estas son sus fichas: " << endl;
		cout<< showPlayerRack() << endl; //para mostrar las fichas nuevas del jugador;
		cout << "Ingrese la letra que quiere cambiar: ";	cin >> letra;
		if (verificarFichaAtril(letra)) { //VERIFICA QUE LA LETRA EXISTA EN EL ATRIL DEL JUGADOR
			for (int i = 0; i < 7; i++) {//para recorrer el rackJugador
				if (rack[i]->getLetra() == letra) {
					saco->AgregarFicha(rack[i]); //recibe todo el objeto 
					rack[i] = saco->fichaRandom(); //genera una ficha random y le cae encima 
					cont++;
					break; //para que solo se haga 1 vez
				}//fin del if
			}//fin del for
		}//fin del if
		cout << "Desea cambiar otra ficha?: " << endl;
		cout << "1. Si\2.No";
		cin >> op;
	} while (op == 1 || cont<7); //se repita las veces que el usuario quiera
	cout << "Sus nuevas fichas: " << endl;
	cout<< showPlayerRack() << endl; //para mostrar las fichas nuevas del jugador;
	if (turno == true)
		turno = false;
}//fin del metodo cambiarFichas