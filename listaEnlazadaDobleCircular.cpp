#include <iostream>

#include <conio.h>

#include <stdlib.h>

#include <string>



using namespace std;



struct nodo

{

	string nombre;

	int valor;

	nodo* anterior;

	nodo* siguiente;

} *primero = NULL, * ultimo = NULL;



void insertar_nodo();

void ver_lista_PaU();



int main() {

	int opc;


	do {

		system("cls");

		cout << "menu";

		cout << "\n1-Insertar 			5-Desplegar PaU";

		cout << "\n2-Buscar			6-Desplegar UaP";

		cout << "\n3-Modificar			7-Salir";

		cout << "\n4-Eliminar";

		cout << "\nOpccion  ";

		cin >> opc;



		switch (opc) {

		case 1:

			cout << "Insertar" << '\n';

			insertar_nodo();

			
			break;

		case 2:

			cout << "Buscar" << '\n';

			
			break;

		case 3:

			cout << "Modificar" << '\n';

			
			break;

		case 4:

			cout << "Eliminar" << '\n';

			

			break;

		case 5:

			cout << "Desplegar PaU" << '\n';

			ver_lista_PaU();

		

			break;

		case 6:

			std::cout << "Desplegar UaP" << '\n';

			
			break;

		case 7:

			std::cout << "Salir" << '\n';

			
			break;

		default:

			cout << "opcion no valida" << '\n';

		}



	} while (opc != 7);



	return 0;

}







void insertar_nodo() {

	nodo* nuevo = new nodo();



	cout << "Ingresa el nombre de variable  y valor: " << endl;

	cin >> nuevo->nombre;

	cin >> nuevo->valor;



	if (primero == NULL) {

		primero = nuevo;

		ultimo = nuevo;

		primero->siguiente = primero;

		primero->anterior = ultimo;

	}
	else {

		ultimo->siguiente = nuevo;

		nuevo->anterior = ultimo;

		nuevo->siguiente = primero;

		ultimo = nuevo;

		primero->anterior = ultimo;

	}



	cout << "Dato ingresado" << '\n';

};








void ver_lista_PaU() {

	nodo* actual = new nodo();

	actual = primero;

	if (primero != NULL) {

		do {

			cout << actual->nombre << " " << actual->valor << "->";

			actual = actual->siguiente;

		} while (actual != primero);

	}
	else {

		std::cout << "Lista vacia" << endl;

	}



}