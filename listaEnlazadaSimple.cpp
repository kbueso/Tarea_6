#include <iostream>
#include <conio.h>

using namespace std;

struct nodo {
    int nro;
    struct nodo* sgte;
    struct nodo* ant;
};
typedef struct nodo* Tlista;
void insertar(Tlista&, int);

bool buscar(Tlista&, int, int&);

void imprimir(Tlista);
int main()
{
    Tlista lista = NULL;
    int valor, opc, pos;
    bool R;
    do
    {
        cout << "1. Insertar al Inicio" << endl;

        cout << "2. Busqueda" << endl;

        cout << "3. Ver Lista" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese Opcion:";
        cin >> opc;
        char opc0 = 's';
        switch (opc)
        {
        case 1: while (opc0 == 's' || opc0 == 'S')
        {
            cout << "Ingrese valor al inicio:";
            cin >> valor;
            insertar(lista, valor);
            cout << endl;
            cout << "Seguir ingresando [s/n]: ";cin >> opc0;
        }
              break;

        case 2: cout << "***Buscar un Valor de la lista***" << endl;
            cout << "Ingrese valor a buscar:";
            cin >> valor;
            imprimir(lista);
            R = buscar(lista, valor, pos);
            if (R == true)
            {
                cout << "El valor buscado es:" << valor;
                cout << "Posicion:" << pos;
            }
            else
            {
                cout << "Valor buscado es:" << valor;
                cout << "Posicon: Ninguna";
            }
            break;

        case 3: cout << "Listado" << endl;
            imprimir(lista);
            break;
        }
        //clrscr();
    } while (opc != 4);
}
void insertar(Tlista& lista, int valor)
{
    Tlista nuevo, actual;
    nuevo = new(struct nodo);
    nuevo->nro = valor;
    actual = lista;
    if (lista == NULL)
    {
        lista = nuevo;
        lista->ant = NULL;
        lista->sgte = NULL;
    }
    else
    {
        nuevo->sgte = lista;
        nuevo->ant = lista->ant;
        lista->ant = nuevo;
        lista = nuevo;
    }
}


bool buscar(Tlista& lista, int valor, int& pos)
{
    Tlista aux = lista;
    pos = 0;
    while (aux != NULL)
    {
        if (aux->nro == valor)
        {
            return true;
        }
        aux = aux->sgte;
        pos++;
    }
    return false;
}
void imprimir(Tlista lista)
{
    Tlista aux = lista;
    int i = 0;
    while (lista != NULL)
    {
        cout << "N[" << i << "] = {" << lista->nro << "}, ";
        lista = lista->sgte;
        i++;
    }
    if (i == 0)
    {
        cout << "nLa lista no tiene datos ... Press Enter";
    }
}