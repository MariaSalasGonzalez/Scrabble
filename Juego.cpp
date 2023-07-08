#include "Diccionario.h"
#include "Ficha.h"
#include "Tablero.h"
#include "Saco.h"
#include "Jugador.h"
#include "Juego.h"

Juego::Juego() { //se inicializa cada puntero con los construcotres de cada clase referente
	diccionario = new Diccionario;
	tablero = new Tablero;
	saco = new Saco;
	NumJugadores = 0;
	//campo para variables
	posicion = 0; //esta variable sirve para poder hacer que un metodo sea general para todos y cambia cuando los turnos lo hacen
	contador = 0; //para que tenga 
	primeraVez = false; //este se cambia a true cuando ya se cumpla el primer turno de todo el juego
	exito = false;
}

void Juego::jugadoresArray() { //de esta manera se crea un arreglo dinamico a objetos estaticos segun la cantidad de jugadores que hayan
	int cant;
	cout << "cuantos jugadores van a participar:" << endl;
	cout << "[2]= 2 jugadores" << endl;
	cout << "[3]= 3 jugadores" << endl;
	cout << "[4]= 4 jugadores" << endl;
	cout << "Su opcion: ";	cin >> cant;
	while (cant<2 || cant > 4) { //solo 2, 3 o 4
		cout << "Opcion incorrecta, ingrese una cantidad correcta" << endl;
		cout << "Su opcion: ";	cin >> cant;
	}
	NumJugadores=cant;
		//puedo hacer un for para recorrer el tamaño del arreglo e iniicalizar
		if (NumJugadores == 2) {
			Jugador uno("Samanta");
			Jugador dos("Felipe");
			jugadores = new Jugador[2]; //asi se crea el arreglo dinamico que contiene objetos de tipo jugador
			jugadores[0] = uno;
			jugadores[1] = dos;
			jugadores[0].fillRack(saco); //de esta manera se llena cada saco del jugador
			jugadores[1].fillRack(saco);
			jugadores[0].setTurno(true); //para que este moviendose con el turno
			jugadores[1].setTurno(false);
		} //fin del if que inicializa 2 jugadores
		if (NumJugadores == 3) {
			Jugador uno("Samanta");
			Jugador dos("Felipe");
			Jugador tres("Giancarlo");
			jugadores = new Jugador[3];
			jugadores[0] = uno;
			jugadores[1] = dos;
			jugadores[2] = tres;
			jugadores[0].fillRack(saco); //de esta manera se llena cada saco del jugador
			jugadores[1].fillRack(saco);
			jugadores[2].fillRack(saco);
			jugadores[0].setTurno(true); //para que este moviendose con el turno
			jugadores[1].setTurno(false);
			jugadores[2].setTurno(false);
		}//fin cuando son 3 jugadores
		if (NumJugadores == 4) {
			Jugador uno("Samanta");
			Jugador dos("Felipe");
			Jugador tres("David");
			Jugador cuatro("Sora");
			jugadores = new Jugador[4];
			jugadores[0] = uno;
			jugadores[1] = dos;
			jugadores[2] = tres;
			jugadores[3] = cuatro;
			jugadores[0].fillRack(saco); //de esta manera se llena cada saco del jugador
			jugadores[1].fillRack(saco);
			jugadores[2].fillRack(saco);
			jugadores[3].fillRack(saco);
			jugadores[0].setTurno(true); //para que este moviendose con el turno
			jugadores[1].setTurno(false);
			jugadores[2].setTurno(false);
			jugadores[3].setTurno(false);
		}//fin del if para 4 jugadores
} //fin del constructor del arreglo de jugadores

void Juego::TurnosPlayers(){ //aqui solo se va a mover de un jugador a otro y se va a jugar
	jugadoresArray(); //se inicializan los jugadores y para poder empezar a jugr
	while (true) { //se va a realizar hasta que haya un ganador (mientras no haya un ganador )
		if (NumJugadores == 2) { //si solo hay 2 jugadores
			if (jugadores[0].getTurno() == true && jugadores[1].getTurno()==false) {
				//mostrar datos para saber en cual jugador esta
				cout << jugadores[0].getNombre() << endl;
				cout << "La cantidad de fichas que quedan en el saco: "; cout << saco->getNumFichas() << endl;
				MenuJugador(); //llama a menuJugadores para que vean las opciones disponibles
				jugadores[0].setTurno(false);
				jugadores[1].setTurno(true);
				posicion = 1; 
				system("pause");
				system("cls");
				/*********************************** */ }//llave del if del primer jugador
			else
				if (jugadores[1].getTurno() == true && jugadores[0].getTurno() == false) {
					//mostrar datos para saber en cual jugador esta
					cout << jugadores[1].getNombre() << endl;
					cout << "La cantidad de fichas que quedan en el saco: "; cout << saco->getNumFichas() << endl;
					MenuJugador(); // llama a ingresar
					jugadores[1].setTurno(false);
					jugadores[0].setTurno(true);
					posicion = 0; //se va a estar cambiando
					system("pause");
					system("cls");
				/*********************************** */ }//llave del if del segundo jugador
		}//llave del if jugadores 2
		
		if (NumJugadores == 3) {
			if (jugadores[0].getTurno() == true && jugadores[1].getTurno() == false && jugadores[2].getTurno()==false) {
				//mostrar datos para saber en cual jugador esta
				cout << jugadores[0].getNombre() << endl;
				cout << "La cantidad de fichas que quedan en el saco: "; cout << saco->getNumFichas() << endl;
				MenuJugador(); //llama a menuJugadores para que vean las opciones disponibles
				jugadores[0].setTurno(false);
				jugadores[1].setTurno(true);
				jugadores[2].setTurno(false);
				posicion = 1;
				system("pause");
				system("cls");
				/*********************************** */	}//llave del if del primer jugador
			else 
				if (jugadores[0].getTurno() == false && jugadores[1].getTurno() == true && jugadores[2].getTurno() == false) {
					//mostrar datos para saber en cual jugador esta
					cout << jugadores[1].getNombre() << endl;
					cout << "La cantidad de fichas que quedan en el saco: "; cout << saco->getNumFichas() << endl;
					MenuJugador(); // llama a ingresar
					jugadores[0].setTurno(false);
					jugadores[1].setTurno(false);
					jugadores[2].setTurno(true);
					posicion = 2; //se va a estar cambiando
					system("pause");
					system("cls");
					/*********************************** */	}//llave del if del segundo jugador
		else
			if (jugadores[0].getTurno() == false && jugadores[1].getTurno() == false && jugadores[2].getTurno() == true) {
				//mostrar datos para saber en cual jugador esta
				cout << jugadores[2].getNombre() << endl;
				cout << "La cantidad de fichas que quedan en el saco: "; cout << saco->getNumFichas() << endl;
				MenuJugador(); // llama a ingresar
				jugadores[0].setTurno(true);
				jugadores[1].setTurno(false);
				jugadores[2].setTurno(false);
				posicion = 0; //se va a estar cambiando
				system("pause");
				system("cls");
				/*********************************** */	}//llave del if del tercer jugador
		}//fin del if de numJugadores==3

		if (NumJugadores == 4) {
			if (jugadores[0].getTurno() == true && jugadores[1].getTurno() == false && jugadores[2].getTurno() == false && jugadores[3].getTurno() ==false) {
				//mostrar datos para saber en cual jugador esta
				cout << jugadores[0].getNombre() << endl;
				cout << "La cantidad de fichas que quedan en el saco: "; cout << saco->getNumFichas() << endl;
				MenuJugador(); //llama a menuJugadores para que vean las opciones disponibles
				jugadores[0].setTurno(false);
				jugadores[1].setTurno(true);
				jugadores[2].setTurno(false);
				jugadores[3].setTurno(false);
				posicion = 1;
				system("pause");
				system("cls");
				/*********************************** */	}//llave del if del primer jugador
			else
				if (jugadores[0].getTurno() == false && jugadores[1].getTurno() == true && jugadores[2].getTurno() == false && jugadores[3].getTurno() == false) {
					//mostrar datos para saber en cual jugador esta
					cout << jugadores[1].getNombre() << endl;
					cout << "La cantidad de fichas que quedan en el saco: "; cout << saco->getNumFichas() << endl;
					MenuJugador(); // llama a ingresar
					jugadores[0].setTurno(false);
					jugadores[1].setTurno(false);
					jugadores[2].setTurno(true);
					jugadores[3].setTurno(false);
					posicion = 2; //se va a estar cambiando
					system("pause");
					system("cls");
					/*********************************** */ }//llave del if del segundo jugador
				else
					if (jugadores[0].getTurno() == false && jugadores[1].getTurno() == false && jugadores[2].getTurno() == true && jugadores[3].getTurno() == false) {
						//mostrar datos para saber en cual jugador esta
						cout << jugadores[2].getNombre() << endl;
						cout << "La cantidad de fichas que quedan en el saco: "; cout << saco->getNumFichas() << endl;
						MenuJugador(); // llama a ingresar
						jugadores[0].setTurno(false);
						jugadores[1].setTurno(false);
						jugadores[2].setTurno(false);
						jugadores[3].setTurno(true);
						posicion = 3; //se va a estar cambiando
						system("pause");
						system("cls");
						/*********************************** */	}//llave del if del tercer jugador
					else
						if (jugadores[0].getTurno() == false && jugadores[1].getTurno() == false && jugadores[2].getTurno() == false && jugadores[3].getTurno() == true) {
							//mostrar datos para saber en cual jugador esta
							cout << jugadores[3].getNombre() << endl;
							cout << "La cantidad de fichas que quedan en el saco: "; cout << saco->getNumFichas() << endl;
							MenuJugador(); // llama a ingresar
							jugadores[0].setTurno(true);
							jugadores[1].setTurno(false);
							jugadores[2].setTurno(false);
							jugadores[3].setTurno(false);
							posicion = 0; //se va a estar cambiando
							system("pause");
							system("cls");
							/*********************************** */	}//llave del if del cuarto jugador
		}//fin del if de numJugadores==4

	}//fin del while //para que se repita
} //fin de TurnosPlayers


void Juego::Jugar() { //aqui solo se llama a Turnos Players para que se ejecute el juego
	cout<<tablero->toString();
	tablero->Instrucciones();
	system("pause");
	system("cls");
	//lo de arriba es para probar

	TurnosPlayers(); //al final para que corra el juego con los turnos de cada jugador
}

void Juego::IngresarLetra()	{ // para ingresar las letras de cada palabra
	char letra;
	int op=0;
	int f; int c;
	string palabra = "";
	
		if (primeraVez == false) {
			IngresarLetraPrimera(); //para que ingrese la palabra por primera vez
			primeraVez = true; //y ahora cambia a true para que ya no se repita
			system("pause");
		} //fin del primer turno al ingresar una palabra
		else {
			do {
			cout << "\nEstas son sus fichas " << jugadores[posicion].getNombre() << " : " << endl;
			cout << jugadores[posicion].showPlayerRack(); //MUESTRA CADA VEZ LAS LETRAS QUE TIENE DISPONIBLE EL USUARIO
			cout << "Digite una letra: ";	cin >> letra;

			if (jugadores[posicion].verificarFichaAtril(letra)) { // el "posicion" esta como atributo y asi verifica que la letra este en el atril
				cout << tablero->toString() << endl; //para que vea las coordenadas de la matriz
				cout << "Cual fila?: "; cin >> f;
				cout << "Cual columna?: ";  cin >> c;

				if (tablero->VerificarCruz(f, c) && tablero->verificarFilaColumna(f, c)) { //verifica que se pueda insertar en esas posiciones
					tablero->guardarPosiciones(f, c); //guarda las posiciones por si aquello de que la palabra este mala
					tablero->insertar(f, c, letra); //aqui inserta en la matriz la letra
					jugadores[posicion].LlenarCopia(letra, jugadores[posicion].getPunto(letra));
					jugadores[posicion].eliminarFichasRack(letra);
					palabra += letra; //para que el usuario vea la palabra como se va formando
					cout << "Su palabra: " << palabra << endl; //letetr cambia a cada rato
					cout << tablero->toString(); //para ir viendo como se inserta la letra en el tablero
					system("pause");
					system("cls");
				} //if de verificar fila y columna y en "cruz"
				else
					cout << "Fila y columna incorrecta u ocupada, ingrese otras" << endl;
			} //if de verificar la letra (el grande)
			else {
				cout << "Ingrese otra letra ya que no posee esa en su atril" << endl;
			}
			cout << "Desea poner otra letra? \t1=SI || 2=NO" << endl << "Opcion: "; cin >> op;
		} while (op != 2); //o ya no tenga mas fichas para poner
		if (diccionario->revisarPalabra(palabra)) { //REVISA LA PALABRA COMPLETA EN EL DICCIONARIO
			cout << "Palabra terminada: [" << palabra << "]" << endl; //asi vemos la palabra terminada
			jugadores[posicion].RellenarRack(saco); //se le manda el sacoactualizado para que rellene sus fichas vacias
			cout << "\nEstas son sus fichas nuevas " << jugadores[posicion].getNombre() << ": " << endl;
			cout << jugadores[posicion].showPlayerRack(); //para ver las nuevas fichas del jugador
			tablero->setDevuelva(0); //para que no de errores cuando verifica la letra
			exito = true;
			cout << endl;
		}
		else { //cuando la palabra no sea correcta
			cout << "palabra incorrecta, ingrese otra" << endl;
			tablero->devolverPosiciones(); //de la matriz
			jugadores[posicion].DevolverCopia(); //devuelve las fichas usadas por el usuario
			cout << "\nEstas son sus fichas" << endl;
			cout << jugadores[posicion].showPlayerRack();
			cout << endl;
		}
		cout << tablero->toString() << endl;
		palabra = ""; //se limpia la palabra
	} //fin del else
}//fin del metodo IngresarLetra


void Juego::MenuJugador() {
	int op = 0;
	do {
		cout << "\nEstas son sus fichas " << jugadores[posicion].getNombre() << " : " << endl;
		cout << jugadores[posicion].showPlayerRack();
		cout << "Sus opciones son: " << endl;
		cout << "\t1.Poner una palabra\n\t2.Cambiar fichas\n\t3.Pasar de turno" << endl << endl;
		cout << "Ingrese su opcion: ";	cin >> op;
		system("pause");
		system("cls");
		switch (op) {
		case 1: { //poner una palabra
			IngresarLetra(); //llama a ingresa letra
			break;
		}
		case 2: //cambiar fichas del atril
			jugadores[posicion].cambiarFichas(saco); //se le manda el saco actualizado
			cout << "Fichas del saco: " << endl;
			saco->mostrarFichas();
			cout << "cantidad de fichas del saco: " << endl << saco->getNumFichas();
			break;
		case 3: //pasar de turno
			jugadores[posicion].setTurno(false);
			break;               
		}//fin del switch
	} while (op ==1 ); //se mantenga solo cuando las opciones con validas
}//fin del metodoMenuJugadores

void Juego::IngresarLetraPrimera() { //lo mismo que ingresarLetra normal pero verificando que al menos una de las letras toque el centro del tablero
	char letra;
	int op = 0;
	int f; int c;
	string palabra = "";
	
	cout << "***************************************************" << endl;
	cout << "Primera Vez que se ingresa una palabra al tablero" << endl;
	cout << "***************************************************" << endl;
		do { //ES UN CICLO PARA FORMAR LA PALABRA
		cout << "\nEstas son sus fichas 7u7r " << jugadores[posicion].getNombre() << ": " << endl;
		cout << jugadores[posicion].showPlayerRack(); //MUESTRA CADA VEZ LAS LETRAS QUE TIENE DISPONIBLE EL USUARIO
		cout << "Digite una letra: ";	cin >> letra;

		if (jugadores[posicion].verificarFichaAtril(letra)) { // el "posicion" esta como atributo y asi verifica que la letra este en el atril
			cout << tablero->toString() << endl; //para que vea las coordenadas de la matriz
			cout << "Cual fila?: "; cin >> f;
			cout << "Cual columna?: ";  cin >> c;

			if (tablero->verificarFilaColumnaPrimeraVez(f, c) ) { //verifica que se pueda insertar en esas posiciones por primera vez
				tablero->guardarPosiciones(f, c); //guarda las posiciones por si aquello de que la palabra este mala
				tablero->insertar(f, c, letra); //aqui inserta en la matriz la letra
				jugadores[posicion].LlenarCopia(letra, jugadores[posicion].getPunto(letra));
				jugadores[posicion].eliminarFichasRack(letra);
				palabra += letra; //para que el usuario vea la palabra como se va formando
				cout << "Su palabra: " << palabra << endl; //la palabra se va mostrarndo al formarse
				cout << tablero->toString(); //para ir viendo como se inserta la letra en el tablero
				system("pause");
				system("cls");
			} //if de verificar fila y columna
			else
				cout << "La letra no existe en sus letras" << endl;
		} //if de verificar la letra (el grande)
		cout << "Desea poner otra letra? \t1=SI || 2=NO" << endl << "Opcion: "; //cuando ya formo la palabra
		cin >> op;
	} while (op == 1); //o ya no tenga mas fichas para hacer una palabra
	
	if (tablero->verificarFichaCentro()) { //VERIFICA QUE EXISTA AL MENOS UNA LETRA EN EL CENTRO DEL TABLERO
		if (diccionario->revisarPalabra(palabra)) { //REVISA LA PALABRA COMPLETA
			cout << "Palara terminada: [" << palabra << "]" << endl;
			jugadores[posicion].RellenarRack(saco); //se le manda el saco
			tablero->ResetMatriz(); //RESETEA LAS COPIAS QUE SE TIENEN DE LA MATRIZ
			cout << tablero->toString(); //para ir viendo como se inserta la letra en el tablero
		} //si revisar la palabra existe
		else { //cuando la palabra no sea correcta
			cout << "palabra incorrecta, ingrese otra" << endl;
			jugadores[posicion].DevolverCopia(); //devuelve las fichas usadas por el usuario
			tablero->devolverPosiciones(); //devuelve la matriz a la normalidad
			tablero->ResetMatriz(); //resetea los arreglos que contenian las posiciones de la matriz modificada
			cout << tablero->toString(); //para ir viendo como se inserta la letra en el tablero
			cout << "\nEstas son sus fichas devueltas" << jugadores[posicion].getNombre() << ": " << endl;			
			cout << jugadores[posicion].showPlayerRack();
			cout << endl;
		} //fin del else de palabra==false

	} //if de fichaCentro
	else {
		cout << "Al menos una ficha debe tocar el centro, tenlo en mente" << endl;
		tablero->devolverPosiciones(); //de la matriz
		tablero->ResetMatriz(); //resetea la matriz
		
	} //else de cuando una ficha no toca el centro


	cout << "7u7r" << endl;
	palabra = ""; //se limpia la palabra
} //fin del InsertarLetraPrimera...vez