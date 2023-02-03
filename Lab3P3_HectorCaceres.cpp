// Lab3P3_HectorCaceres.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "iostream"
#include "string"
#include <math.h>
#include <conio.h>
using namespace std;


//// LIBRERIA RANDOM
#include <stdlib.h>
#include <time.h>



/////////////////////////// EJERCICIO 1 /////////////////////////////////
int x[400];
int tam = 0;
double suma = 0, prom = 0;

void tamano_arreglo(int n) {
	tam = n;
}

void ver_arreglo() {

	for (int i = 0; i < tam; i++) {
		cout << " " << x[i] << " ";
	}

}

void aleatorio() {
	srand(time(NULL));
	int DESDE = 100, HASTA = 500;

	for (int i = 0; i < tam; i++) {
		x[i] = rand() % (HASTA - DESDE + 1) + DESDE;
	}

}


void media() {

	for (int i = 0; i < tam; i++) {
		suma = suma + x[i];
	}
	prom = (suma / tam);
	cout << "LA MEDIA ES = " << prom << endl;

}


void mediana() {
	cout << "   DATOS ORGANIZADOS ( ORDENADOS )" << endl;
	cout << "-----------------------------------\n\n\n" << endl;
	cout << "\n" << endl;

	int aux = 0;

	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam - 1; j++) {
			if (x[j] > x[j + 1]) {
				aux = x[j];
				x[j] = x[j + 1];
				x[j + 1] = aux;

			}
		}
	}

	for (int i = 0; i < tam; i++) {
		cout << "[" << x[i] << "]    ";

	}

	int central = 0, mitad = 0;

	for (int i = 0; i < tam; i++) {
		if (tam % 2 == 0) {
			mitad = (tam / 2);
			central = (x[mitad - 1] + x[mitad]) / 2;
		}
		else {
			mitad = ((tam - 1) / 2);
			central = x[mitad];
		}
	}

	cout << "\n\n\n" << endl;
	cout << "LA MEDIANA EL Nº DEL MEDIO ES = " << central << endl;
}

//////////////////////////// EJERCICIO 1 ////////////////////////////////////////






//////////////////////////// EJERCICIO 2 ////////////////////////////////////////

double resultado = 0;

void ingresar_datos(int x, int n, int ii) {
	double min = 1, mid = 0, max = x;



	for (int i = 0; i < ii; i++) {
		if (mid > x) {
			min = min - 1;
			max = mid - 1;
		}
		else {
			min = min - 1;
			max = max - 1;
		}

	}
	mid = (min + max) / 2;

	cout << "RESULTADO DE MID = " << mid << endl;


	cout << "\n\n\n" << endl;

	cout << "RAIZ (" << n << ") DE (" << x << ") : " << mid << endl;
	resultado = mid;
}

void calcular_mid_elevado_n(int n) {
	cout << "MID ELEVADO A LA N : " << pow(resultado, n);
}



//////////////////////////// EJERCICIO 2 ////////////////////////////////////////







//////////////////////////// EJERCICIO 3 ////////////////////////////////////////

int matriz[30][30];
int fil = 0, col = 0;


void tamano_matriz(int a, int b) {
	fil = a;
	col = b;
}

void ver_matriz() {
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			cout << " " << matriz[i][j] << " ";
		}
		cout << "" << endl;
	}

}


void aleatorio_matriz() {
	srand(time(NULL));
	int DESDE = 2, HASTA = 50;

	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			matriz[i][j] = rand() % (HASTA - DESDE + 1) + DESDE;
		}
	}

}


bool esPrimo(int numero) {

	if (numero == 0 || numero == 1 || numero == 4) return false;
	for (int x = 2; x < numero / 2; x++) {
		if (numero % x == 0) return false;
	}

	return true;
}

void numeros_primos_matriz() {

	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			if (esPrimo(matriz[i][j])) {
				cout << " " << matriz[i][j] << " : SI ";
			}
			else {
				cout << " " << matriz[i][j] << " : NO ";
			}
		}
		cout << "" << endl;
	}



	cout << "\n\n\n" << endl;

	cout << "NUMEROS PRIMOS EN LA MATRIZ SON : ";

	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			if (esPrimo(matriz[i][j])) {
				cout << " " << matriz[i][j] << " ";
			}
		}
	}

}


//////////////////////////// EJERCICIO 3 ////////////////////////////////////////


int main(int argc, char** argv) {
	int op = 0, n = 0;
	int a = 0, b = 0;
	////////////////
	double aa = 0, bb = 0, cc = 0, rr = 0;


	while (op != 4) {
		cout << "\n\n" << endl;

		cout << "    MENU" << endl;
		cout << "------------------\n\n" << endl;

		cout << "1). PRACTICA (1) : CALCULAR LA MEDIA & MEDIANA" << endl;
		cout << "2). PRACTICA (2) : RAIZ N X MEDIANTE BUSQUEDAD BINARIA " << endl;
		cout << "3). PRACTICA (3) : NUMEROS PRIMOS DE UNA MATRIZ " << endl;
		cout << "4). SALIR" << endl;
		cout << "\n" << endl;

		cout << "OPCION --> ";
		cin >> op;

		cout << "\n\n" << endl;

		switch (op) {

		case 1:
			cout << "INGRESE LA CANTIDAD DE DATOS : ";
			cin >> n;


			cout << "\n\n" << endl;

			if (n >= 5 & n <= 20) {
				cout << "! ARREGLO GENERADO !" << endl;
				cout << "\n\n" << endl;
				tamano_arreglo(n);
				aleatorio();
				ver_arreglo();

				cout << "\n\n" << endl;

				cout << "CALCULAR LA MEDIA : " << endl;
				cout << "------------------------------" << endl;
				cout << "\n" << endl;

				media();

				cout << "\n\n" << endl;
				mediana();
				cout << "\n\n" << endl;

			}
			else {
				cout << "! ERROR FUERA DEL RANGO NO PERMITIDO !" << endl;
			}

			break;
		case 2:

			cout << "INGRESE VALOR N (RAIZ INDICE) : ";
			cin >> aa;
			cout << "INGRESE VALOR X (RADICANDO) : ";
			cin >> bb;
			cout << "INGRESE Nº MAXIMO ITERACIONES : ";
			cin >> cc;

			cout << "\n\n" << endl;

			if (cc >= 10) {
				ingresar_datos(aa, bb, cc);
				calcular_mid_elevado_n(aa);
			}
			else {
				cout << "! ERROR FUERA DEL RANGO NO PERMITIDO !" << endl;
			}



			break;
		case 3:

			cout << "INGRESE EL VALOR DE LA FILA : ";
			cin >> a;
			cout << "INGRESE EL VALOR DE LA COLUMNA : ";
			cin >> b;

			cout << "\n\n" << endl;

			if (a >= 5 & b >= 5) {
				cout << "! MATRIZ GENERADO !" << endl;
				cout << "\n\n" << endl;
				tamano_matriz(a, b);
				aleatorio_matriz();
				ver_matriz();
				cout << "\n\n" << endl;
				numeros_primos_matriz();

			}
			else {
				cout << "! ERROR FUERA DEL RANGO NO PERMITIDO !" << endl;
			}


			break;
		case 4:
			cout << "SALIENDO..." << endl;
			break;
		default:
			cout << "! OPCION INCORRECTO !" << endl;
			break;
		}

		cout << "\n\n" << endl;
	}


	system("PAUSE");
	return 0;
}
