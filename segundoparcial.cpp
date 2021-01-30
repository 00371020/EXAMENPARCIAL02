#include <iostream>

using namespace std;

struct nodo{
    int dato;
    nodo *ant;
    nodo *sig;
};

class ListaDoble{
    private:
        nodo *pInicio;
    
    public:
        ListaDoble();
        ~ListaDoble();
        void insertarEnLista(void);
        void mostrarLista(void);
        void insertarAntesDeElemento(int, int);
        void buscarRec(int datoB);
        bool buscarRecAux(nodo *p, int datoB); 
        void sumaypromedio(void); 
};

ListaDoble::ListaDoble(void)
{
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void)
{
    nodo *p;

    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertarEnLista(void)
{
    int dato, datoRef;

    cout << "Digite un entero o Ctrl-Z para terminar: ";
    while(cin >> dato){
        cout << "Digite el elemento antes del cual insertara: ";
        cin >> datoRef;
        insertarAntesDeElemento(dato, datoRef);
        cout << "Digite un entero o Ctrl-Z para terminar: ";
    }
}

void ListaDoble::insertarAntesDeElemento(int dato, int datoRef)
{
    nodo *nuevo = new nodo;
    
    nuevo->dato = dato;
   

    if (!pInicio)
    {
        pInicio = nuevo;
        pInicio->sig = NULL;
        pInicio->ant = NULL;
    }
    else
    {
        if (pInicio->dato == datoRef)
        {   
            nuevo->ant = NULL;
            nuevo->sig = pInicio;
            pInicio = nuevo;
        }
        else
        {
            nodo *s = pInicio;
            while (s->sig && s->sig->dato != datoRef)
            {
                s = s->sig;
            }
            if (s)
            {
                nuevo->sig = s->sig;
                s->sig = nuevo;
                nuevo->ant = s;
            }
            else
            {
                nuevo->sig = NULL;
                nuevo->ant = s->sig;
            }
        }
    }

}

void ListaDoble::mostrarLista(void)
{
    nodo *p;
    cout << "Los elementos de la lista son:" << endl;
    p = pInicio;
    while(p->sig){
        cout << p->dato << endl;
        p = p->sig;
    }
    cout << p->dato << endl;
    cout << "Fin de mostrar lista" << endl;
}

void ListaDoble::buscarRec(int datoB)
{
    if(buscarRecAux(pInicio, datoB))
        cout << "Si lo encontre" << endl;
    else
        cout << "No lo encontre" << endl;
}

bool ListaDoble::buscarRecAux(nodo *p, int datoB)
{
    if (p && (p->dato != datoB))
        buscarRecAux(p->sig, datoB);
    else if (p)
        return true;
    else
        return false;
}

void ListaDoble::sumaypromedio(void)
{
    nodo *p;
    int contadorDnodos = 0;
    float suma = 0, prom = 0;

    p = pInicio;

    while (p)
    {
        suma = suma + p->dato;
        p = p->sig;
        contadorDnodos++;
    }

    prom = (suma/contadorDnodos);

    cout << "La suma es: "<< suma << endl;
    cout << "El promedio es: " << prom; 
    
}

int main(void)
{
    ListaDoble objListaDoble;

    cout << endl;
    cout << "PROGRAMA DEL SEGUNDO EXAMEN PARCIAL" << endl << endl;

    cout << "Insercion de datos en la lista:" << endl;
    objListaDoble.insertarEnLista();

    objListaDoble.mostrarLista();

    cin.clear();
    int datoB;
    cout << "Que dato desea buscar? ";
    cin >> datoB;
    objListaDoble.buscarRec(datoB);

    objListaDoble.sumaypromedio();
    
    cout << endl;
    return 0;
}
