#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo {
    int nro;   
    struct nodo* sgte; 
};

typedef struct nodo;
nodo* fin;
nodo* lista;

void menu1();
void insertarInicio();
void insertarFinal();
void mostrar();
void buscarElemento();
void eliminarElemento();
void eliminarElementos();


int main(void)
{
    lista = NULL;
    int op;    


    system("color 0a");

    do
    {
        menu1();
        cin >> op;

        switch (op)
        {
        case 1:
            insertarInicio();
            break;

        case 2:
            insertarFinal();
            break;
        case 3:
            cout << "\n\n Lista Circular \n\n";
            mostrar();
            break;

        case 4:
            buscarElemento();
            break;

        case 5:
            eliminarElemento();
            break;
        case 6:
            eliminarElementos();
            break;

        default: cout << "OPCION NO VALIDA...!!!";
            break;


        }

        cout << endl << endl;
        system("pause");  system("cls");

    } while (op != 7);

    return 0;
}


void menu1()
{
    cout << "\n\t\tLISTA ENLAZADA CIRCULAR\n\n";
    cout << " 1. INSERTAR AL INICIO               " << endl;
    cout << " 2. INSERTAR AL FINAL                " << endl;
    cout << " 3. REPORTAR LISTA                   " << endl;
    cout << " 4. BUSCAR ELEMENTO                  " << endl;
    cout << " 5. ELIMINAR ELEMENTO 'V'            " << endl;
    cout << " 6. ELIMINAR ELEMENTOS CON VALOR 'V' " << endl;
    cout << " 7. SALIR                            " << endl;

    cout << "\n INGRESE OPCION: ";
}


void insertarInicio()
{
    nodo* nuevo;
    nuevo = new struct nodo;

    cout << "\n***INSERTA AL INICIO*****\n";
    cout << "\nINGRESE DATO:";
    cin >> nuevo->nro;
    nuevo->sgte = NULL;

    if (lista == NULL)
    {
        cout << "PRIMER ELEMENTO..!!!";
        lista = nuevo;
        lista->sgte = lista;
        fin = nuevo;
    }
    else
    {
        nuevo->sgte = lista;
        lista = nuevo;
        fin->sgte = lista;
    }

}
void insertarFinal()
{
    nodo* nuevo;
    nuevo = new struct nodo;
    cout << "\n***INSERTA AL INICIO*****\n";
    cout << "\nINGRESE DATO:";
    cin >> nuevo->nro;
    nuevo->sgte = NULL;

    if (lista == NULL)
    {
        cout << "PRIMER ELEMENTO..!!!";
        lista = nuevo;
        lista->sgte = lista;
        fin = nuevo;
    }
    else
    {
        fin->sgte = nuevo;
        nuevo->sgte = lista;
        fin = nuevo;
    }
}
void mostrar()
{
    nodo* aux;
    aux = lista;
    int i = 1;

    if (lista != NULL)
    {
        do
        {
            cout << "  " << aux->nro;
            aux = aux->sgte;
            i++;
        } while (aux != lista);
    }
    else
        cout << "\n\n\tLista vacia...!" << endl;


}
void buscarElemento()
                      
{
    nodo* aux;
    int i = 1, valor, flag = 0;

    cout << "\nINGRESE ELEMENTO A BUSCAR:";
    cin >> valor;
    if (lista != NULL)
    {
        aux = lista;

        do
        {
            if (aux->nro == valor)
            {
                cout << "\n\n Encontrado en posicion " << i << endl;
                flag = 1;
            }
            else
            {
                aux = aux->sgte;
                i++;
            }
        } while (aux != lista);

        if (flag == 0) cout << "\n\n\tNumero no econtrado..!" << endl;

    }
    else
        cout << "\n\n\tLista vacia...!" << endl;

}
void eliminarElemento()
{
    nodo* aux, * r, * q;
    int i = 1, flag = 0, valor;

    cout << "\n INGRESE ELEMENTO A ELIMINAR:";
    cin >> valor;

    if (lista != NULL)
    {
        aux = lista;

        do
        {
            if (aux->nro == valor)
            {
                if (aux == lista)
                {
                    r = lista;
                    lista = lista->sgte;
                    aux = aux->sgte;
                    fin->sgte = lista;
                    r->sgte = NULL;
                    if (fin->sgte == NULL)
                    {
                        lista == NULL;
                        aux == NULL;
                        delete(r);
                        cout << "\nELEMENTO ELIMINADO...!!!\n";
                        return;
                    }
                    else
                    {
                        delete(r);
                        cout << "\nELEMENTO ELIMINADO...!!!\n";
                        return;
                    }
                }
                else
                {
                    if (aux == fin)
                    {
                        r = aux;
                        aux = aux->sgte;
                        q->sgte = aux;
                        fin = q;
                        r->sgte = NULL;
                        delete(r);
                        cout << "\nELEMENTO ELIMINADO...!!!\n";
                        return;
                    }
                    else
                    {
                        r = aux;
                        aux = aux->sgte;
                        q->sgte = aux;
                        r->sgte = NULL;
                        delete(r);
                        cout << "\nELEMENTO ELIMINADO...!!!\n";
                        return;
                    }
                }
                flag = 1;
            }
            else
            {
                q = aux;
                aux = aux->sgte;
                i++;
            }
        } while (aux != lista);

        if (flag == 0)
            cout << "\n\n\tNumero no econtrado..!" << endl;


    }
    else
        cout << "LISTA VACIA...!!!!";


}
void eliminarElementos()
{
    nodo* aux, * r, * q;
    int  flag = 0, valor;

    cout << "\n DATO REPETIDO A ELIMINAR:";
    cin >> valor;

    if (lista != NULL)
    {
        aux = lista;

        while (aux->nro == valor)
            if (aux == lista)    
            {
                r = lista;
                aux = lista->sgte;
                lista = lista->sgte;
                fin->sgte = lista;
                r->sgte = NULL;
                if (fin->sgte == NULL)
                {
                    lista == NULL;
                    aux == NULL;
                    delete(r);
                    flag = 1;
                }
                else
                {
                    delete(r);
                    flag = 1;
                }
            }
        do
        {
            if (aux->nro == valor)
            {
                while (aux == lista)
                {
                    r = lista;
                    aux = lista->sgte;
                    lista = lista->sgte;
                    fin->sgte = lista;
                    r->sgte = NULL;
                    if (fin->sgte == NULL)
                    {
                        lista == NULL;
                        aux == NULL;
                        delete(r);
                    }
                    else
                        delete(r);

                }

                if (aux == fin)
                {
                    r = aux;
                    aux = aux->sgte;
                    q->sgte = aux;
                    fin = q;
                    r->sgte = NULL;
                    delete(r);
                }
                else
                {
                    r = aux;
                    aux = aux->sgte;
                    q->sgte = aux;
                    r->sgte = NULL;
                    delete(r);
                }

                flag = 1;
            }
            else
            {
                q = aux;
                aux = aux->sgte;
            }
        } while (aux != lista);

        if (flag == 0)
            cout << "\n\n\tNumero no econtrado..!" << endl;
    }
    else
        cout << "LISTA VACIA...!!!!";
}