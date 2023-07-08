#include "Tablero.h"
Tablero::Tablero() {
	for (int i = 0; i < (sizeof(matriz[0]) / sizeof(matriz[0][0])); i++) {
		for (int j = 0; j < (sizeof(matriz[0]) / sizeof(matriz[0][0])); j++) {
			if ((i == 0 && (j == 0 || j == 7 || j == 14)) ||
				(i == 7 && (j == 0 || j == 14)) ||
				(i == 14 && (j == 0 || j == 0 || j == 14))
				) { //inicio if de rojo =  X3 palabra
				matriz[i][j] = '1';
			} // fin del if de rojo = X3 palabra
			else
				if ((i == 1 && (j == 1 || j == 13)) ||
					(i == 2 && (j == 2 || j == 12)) ||
					(i == 3 && (j == 3 || j == 11)) ||
					(i == 4 && (j == 4 || j == 10)) ||
					(i == 10 && (j == 4 || j == 10)) ||
					(i == 11 && (j == 3 || j == 11)) ||
					(i == 12 && (j == 2 || j == 12)) ||
					(i == 13 && (j == 1 || j == 13))
					) {//inicio if de rosado = X2 palabra
					matriz[i][j] = '2';
				}//fin del if de rosado = X2 palabra
				else
					if ((i == 1 && (j == 5 || j == 9)) ||
						(i == 5 && (j == 1 || j == 5 || j == 9 || j == 13)) ||
						(i == 9 && (j == 1 || j == 5 || j == 9 || j == 13)) ||
						(i == 13 && (j == 5 || j == 9))
						) {//inicio if azul = X3 letra
						matriz[i][j] = '3';
					}//fin if azul = x3 letra
					else
						if ((i == 0 && (j == 4 || j == 10)) ||
							(i == 2 && (j == 6 || j == 8)) ||
							(i == 3 && (j == 0 || j == 7 || j == 14)) ||
							(i == 6 && (j == 2 || j == 6 || j == 8 || j == 12)) ||
							(i == 7 && (j == 3 || j == 11)) ||
							(i == 8 && (j == 2 || j == 6 || j == 8 || j == 12)) ||
							(i == 11 && (j == 0 || j == 7 || j == 14)) ||
							(i == 12 && (j == 6 || j == 8)) ||
							(i == 14 && (j == 4 || j == 10))
							) { //inicio if celeste = X2 letra
							matriz[i][j] = '4';
						}//fin id celeste =X2 letra
						else
							matriz[i][j] = ' ';
		} //for del j
		matriz[7][7] = char(254); //un cuadrito blanco en el centro //segun el codigo ascii
	}//for del i

}//fin del constructot

string Tablero::toString() { //mostrar el tablero actualizado //funciona mejor con el toString
	stringstream t;
	int fila = 0, columna = 0; //para las coordenadas de fila y columna de la matriz
	t << "\t";
	do { //muestra las coordenadas de las columnas
		if (columna>9)
			t << columna << "| ";
		else
			t << columna << " | ";
		columna++;
	} while (columna < 15);
	t << endl << "\t___________________________________________________________" << endl;

	for (int i = 0; i < (sizeof(matriz[0]) / sizeof(matriz[0][0])); i++) {//inicio for i
		t << "[" << fila << "]" << "\t"; //muestra las coordenadas de las filas
		for (int j = 0; j < (sizeof(matriz[0]) / sizeof(matriz[0][0])); j++) {//inicio for j
			t << matriz[i][j] << " |" << " ";
		}//cierre del for j
		fila++;
		t << endl << "\t___________________________________________________________" << endl;
	}//cierre del for i
	return t.str();
} //fin del metodo toString

void Tablero::gotoxy(int x, int y) { //para las posiciones en la pantalla 
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Tablero::Instrucciones() {
	gotoxy(90, 1);	cout << "Instrucciones del Scrabble";
	gotoxy(90, 2);	cout << "1. El juego es para 2, 3 o 4 jugadores";
	gotoxy(90, 3);	cout << "2. El tablero cuenta con posiciones especificas de premio:";
	gotoxy(90, 4);	cout << "\t I) 1 = Rojo: X3 Palabra";
	gotoxy(90, 5);	cout << "\t I) 2 = Rosado: X2 Palabra";
	gotoxy(90, 6);	cout << "\t I) 3 = Azul: X3 Letra";
	gotoxy(90, 7);	cout << "\t I) 4 = Celeste: X2 Letra";
	gotoxy(90, 8);	cout << "3. Los turnos se deciden escogiendo una ficha al azar y el que " << endl;
	gotoxy(90, 9);	cout << "tenga un comodin o la  mas cercana a la \"A\" tiene el primero turno" << endl;
	gotoxy(90, 10);	cout << "4. Cada jugador cuenta de un atril con 7 fichas";
	gotoxy(90, 11);	cout << "5. La primera palabra se coloca con al menos una ficha en el centro del" << endl;
	gotoxy(90, 12);	cout << "tablero(en " << char(254) << ") de manera que se lea de sgt manera: " << endl;
	gotoxy(90, 13);	cout << "\t~Izquierda / Dereha(Horizontal) || Arriba / Abajo(Vertical)" << endl;
	gotoxy(90, 14);	cout << "6. Tiene la oportunidad de:  Colocar la palabra || Pasar su turno || Cambiar" << endl;
	gotoxy(90, 15);	cout << "las fichas del atril por otras" << endl;
	gotoxy(90, 16);	cout << "7. Cuando forma las palabras:" << endl;
	gotoxy(90, 17);	cout << "\t a) Solo se permite horizontal o vertical" << endl;
	gotoxy(90, 18);	cout << "\t b) Puede agregar letras a una palabra ya existente, siempre que tenga" << endl;
	gotoxy(90, 19);	cout << "\t  sentido" << endl;
	gotoxy(90, 20);	cout << "\t c) Puede hacer una palabra de una letra de otra palabra ya formada en" << endl;
	gotoxy(90, 21);	cout << "\t    un angulo recto (como una forma de T) " << endl;
	gotoxy(90, 22);	cout << "\t d) Si alguna letra de los extremos de la palabra toca otra letra de" << endl;
	gotoxy(90, 23);	cout << "\t   una palabra ya creada, ambdas deben tener sentido y se cuentan " << endl;
	gotoxy(90, 24);	cout << "\t   como propias del jugador" << endl << endl << endl << endl << endl << endl << endl;
}//fin de instrucciones
void Tablero::setDevuelva(int num) {
	this->devuelva = num;	}

char Tablero::getPosiciones(int x, int y) { //para cuando se verifique, conocer el contenido de x,y posicion
	return matriz[x][y];
}//fin getPosiciones

void Tablero::insertar(int x, int y , char letra) {//para insertar la letra
	matriz[x][y] = letra;
}

bool Tablero::verificarFilaColumna(int x, int y) { //para validar que puede poner en las posiciones que el jugador indica
	if (matriz[x][y] == ' ' || matriz[x][y] == '1' || matriz[x][y] == '2' || matriz[x][y] == '3' || matriz[x][y] == '4' || matriz[x][y] == char(254) )
		return true; //puede insertar en cualquiera de esas
	else
		return false; //es porque ya tiene alguna letra
}

void Tablero::guardarPosiciones(int f, int c){ //para que guarde lo que se hace en el tablero 
	contenido[devuelva] = matriz[f][c];
	fil[devuelva] = f;
	col[devuelva] = c;
	devuelva++;
} //por si aquello de que el usuario meta una palabra no disponible en el diccionario, asi se guarda por si aquello

void Tablero::devolverPosiciones(){ //devuelve si se equivoco
	int cont = 0;
	while( cont < devuelva){
		matriz[fil[cont]][col[cont]] = contenido[cont];
		cont++;
	}
	devuelva = 0; //resetea la variable para que en cada turno guarde nuevas posiciones
} //si falla la palabra, se devuelve la matriz a su estado normal porque se le devuelve su contenido

void Tablero::ResetMatriz() { //resetea los arreglos que se usaron para almacenar las copias de las posiciones de la matriz
	for (int i = 0; i < 7; i++) {
		fil[i] = 0;
		col[i] = 0;
		contenido[i] = ' ';
		devuelva = 0;
	}
}


bool Tablero::verificarFilaColumnaPrimeraVez(int x, int y) { //el usuario va a ingresar una coordenada, pero solo puede ser entre fila 7 y columna 7
	return (x==7 || y==7); //el solito verifica si la fila es 7 Ó la columna es 7 pues solo ahi puede insertar la primera vez
} //si se empezo en 7,6 , significa que al menor una letra esta en la fila o columna central

bool Tablero::verificarFichaCentro() { //recorrer para ver si la primera posicion
	return (matriz[7][7]!=char(254));
} //que retorne true cuando ya hay una ficha en el centro

bool Tablero::VerificarCruz(int f, int c) { //para que siempre meta tocando una ficha
	if ( (matriz[f - 1][c] == 'A' || matriz[f - 1][c] == 'B' || matriz[f - 1][c] == 'C' || matriz[f - 1][c] == 'D' || matriz[f - 1][c] == 'E' || matriz[f - 1][c] == 'F' || matriz[f - 1][c] == 'G' || matriz[f - 1][c] == 'H' || matriz[f - 1][c] == 'I' || matriz[f - 1][c] == 'J' || matriz[f - 1][c] == 'K' || matriz[f - 1][c] == 'L' || matriz[f - 1][c] == 'M' || matriz[f - 1][c] == 'N' || matriz[f - 1][c] == 'O' || matriz[f - 1][c] == 'P' || matriz[f - 1][c] == 'Q' || matriz[f - 1][c] == 'R' || matriz[f - 1][c] == 'S' || matriz[f - 1][c] == 'T' || matriz[f - 1][c] == 'U' || matriz[f - 1][c] == 'V' || matriz[f - 1][c] == 'W' || matriz[f - 1][c] == 'X' || matriz[f - 1][c] == 'Y' || matriz[f - 1][c] == 'Z' || 
		matriz[f + 1][c] == 'A' || matriz[f + 1][c] == 'B' || matriz[f + 1][c] == 'C' || matriz[f + 1][c] == 'D' || matriz[f + 1][c] == 'E' || matriz[f + 1][c] == 'F' || matriz[f + 1][c] == 'G' || matriz[f + 1][c] == 'H' || matriz[f + 1][c] == 'I' || matriz[f + 1][c] == 'J' || matriz[f + 1][c] == 'K' || matriz[f + 1][c] == 'L' || matriz[f + 1][c] == 'M' || matriz[f + 1][c] == 'N' || matriz[f + 1][c] == 'O' || matriz[f + 1][c] == 'P' || matriz[f + 1][c] == 'Q' || matriz[f + 1][c] == 'R' || matriz[f + 1][c] == 'S' || matriz[f + 1][c] == 'T' || matriz[f + 1][c] == 'U' || matriz[f + 1][c] == 'V' || matriz[f + 1][c] == 'W' || matriz[f + 1][c] == 'X' || matriz[f + 1][c] == 'Y' || matriz[f + 1][c] == 'Z' ||
		matriz[f][c - 1] == 'A' || matriz[f][c - 1] == 'B' || matriz[f][c - 1] == 'C' || matriz[f][c - 1] == 'D' || matriz[f][c - 1] == 'E' || matriz[f][c - 1] == 'F' || matriz[f][c - 1] == 'G' || matriz[f][c - 1] == 'H' || matriz[f][c - 1] == 'I' || matriz[f][c - 1] == 'J' || matriz[f][c - 1] == 'K' || matriz[f][c - 1] == 'L' || matriz[f][c - 1] == 'M' || matriz[f][c - 1] == 'N' || matriz[f][c - 1] == 'O' || matriz[f][c - 1] == 'P' || matriz[f][c - 1] == 'Q' || matriz[f][c - 1] == 'R' || matriz[f][c - 1] == 'S' || matriz[f][c - 1] == 'T' || matriz[f][c - 1] == 'U' || matriz[f][c - 1] == 'V' || matriz[f][c - 1] == 'W' || matriz[f][c - 1] == 'X' || matriz[f][c - 1] == 'Y' || matriz[f][c - 1] == 'Z' ||
		matriz[f][c + 1] == 'A' || matriz[f][c + 1] == 'B' || matriz[f][c + 1] == 'C' || matriz[f][c + 1] == 'D' || matriz[f][c + 1] == 'E' || matriz[f][c + 1] == 'F' || matriz[f][c + 1] == 'G' || matriz[f][c + 1] == 'H' || matriz[f][c + 1] == 'I' || matriz[f][c + 1] == 'J' || matriz[f][c + 1] == 'K' || matriz[f][c + 1] == 'L' || matriz[f][c + 1] == 'M' || matriz[f][c + 1] == 'N' || matriz[f][c + 1] == 'O' || matriz[f][c + 1] == 'P' || matriz[f][c + 1] == 'Q' || matriz[f][c + 1] == 'R' || matriz[f][c + 1] == 'S' || matriz[f][c + 1] == 'T' || matriz[f][c + 1] == 'U' || matriz[f][c + 1] == 'V' || matriz[f][c + 1] == 'W' || matriz[f][c + 1] == 'X' || matriz[f][c + 1] == 'Y' || matriz[f][c + 1] == 'Z' ) 
		) {
		//cout<<"Puede ingresar en esa posicion" porque esta tocando al menos una ficha ya puesta
		return true;
	}
	if ((matriz[f - 1][c] != 'A' && matriz[f - 1][c] != 'B' && matriz[f - 1][c] != 'C' && matriz[f - 1][c] != 'D' && matriz[f - 1][c] != 'E' && matriz[f - 1][c] != 'F' && matriz[f - 1][c] != 'G' && matriz[f - 1][c] != 'H' && matriz[f - 1][c] != 'I' && matriz[f - 1][c] != 'J' && matriz[f - 1][c] != 'K' && matriz[f - 1][c] != 'L' && matriz[f - 1][c] != 'M' && matriz[f - 1][c] != 'N' && matriz[f - 1][c] != 'O' && matriz[f - 1][c] != 'P' && matriz[f - 1][c] != 'Q' && matriz[f - 1][c] != 'R' && matriz[f - 1][c] != 'S' && matriz[f - 1][c] != 'T' && matriz[f - 1][c] != 'U' && matriz[f - 1][c] != 'V' && matriz[f - 1][c] != 'W' && matriz[f - 1][c] != 'X' && matriz[f - 1][c] != 'Y' && matriz[f - 1][c] != 'Z' &&
		matriz[f + 1][c] != 'A' && matriz[f + 1][c] != 'B' && matriz[f + 1][c] != 'C' && matriz[f + 1][c] != 'D' && matriz[f + 1][c] != 'E' && matriz[f + 1][c] != 'F' && matriz[f + 1][c] != 'G' && matriz[f + 1][c] != 'H' && matriz[f + 1][c] != 'I' && matriz[f + 1][c] != 'J' && matriz[f + 1][c] != 'K' && matriz[f + 1][c] != 'L' && matriz[f + 1][c] != 'M' && matriz[f + 1][c] != 'N' && matriz[f + 1][c] != 'O' && matriz[f + 1][c] != 'P' && matriz[f + 1][c] != 'Q' && matriz[f + 1][c] != 'R' && matriz[f + 1][c] != 'S' && matriz[f + 1][c] != 'T' && matriz[f + 1][c] != 'U' && matriz[f + 1][c] != 'V' && matriz[f + 1][c] != 'W' && matriz[f + 1][c] != 'X' && matriz[f + 1][c] != 'Y' && matriz[f + 1][c] != 'Z' &&
		matriz[f][c - 1] != 'A' && matriz[f][c - 1] != 'B' && matriz[f][c - 1] != 'C' && matriz[f][c - 1] != 'D' && matriz[f][c - 1] != 'E' && matriz[f][c - 1] != 'F' && matriz[f][c - 1] != 'G' && matriz[f][c - 1] != 'H' && matriz[f][c - 1] != 'I' && matriz[f][c - 1] != 'J' && matriz[f][c - 1] != 'K' && matriz[f][c - 1] != 'L' && matriz[f][c - 1] != 'M' && matriz[f][c - 1] != 'N' && matriz[f][c - 1] != 'O' && matriz[f][c - 1] != 'P' && matriz[f][c - 1] != 'Q' && matriz[f][c - 1] != 'R' && matriz[f][c - 1] != 'S' && matriz[f][c - 1] != 'T' && matriz[f][c - 1] != 'U' && matriz[f][c - 1] != 'V' && matriz[f][c - 1] != 'W' && matriz[f][c - 1] != 'X' && matriz[f][c - 1] != 'Y' && matriz[f][c - 1] != 'Z' &&
		matriz[f][c + 1] != 'A' && matriz[f][c + 1] != 'B' && matriz[f][c + 1] != 'C' && matriz[f][c + 1] != 'D' && matriz[f][c + 1] != 'E' && matriz[f][c + 1] != 'F' && matriz[f][c + 1] != 'G' && matriz[f][c + 1] != 'H' && matriz[f][c + 1] != 'I' && matriz[f][c + 1] != 'J' && matriz[f][c + 1] != 'K' && matriz[f][c + 1] != 'L' && matriz[f][c + 1] != 'M' && matriz[f][c + 1] != 'N' && matriz[f][c + 1] != 'O' && matriz[f][c + 1] != 'P' && matriz[f][c + 1] != 'Q' && matriz[f][c + 1] != 'R' && matriz[f][c + 1] != 'S' && matriz[f][c + 1] != 'T' && matriz[f][c + 1] != 'U' && matriz[f][c + 1] != 'V' && matriz[f][c + 1] != 'W' && matriz[f][c + 1] != 'X' && matriz[f][c + 1] != 'Y' && matriz[f][c + 1] != 'Z')
		) { //revisa los 4 lados 
		//cout<<" NO Puede ingresar en esa posicion pues no toca ninguna ficha"
		return false;
	}
}//fin del metodo VerificaCruz

