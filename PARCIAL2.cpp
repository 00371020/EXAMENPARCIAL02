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
    int dato, datoRef, otra = 0;

    do
    {
        cout << "Digite un entero: "; cin >> dato;
        cout << "Digite el elemento antes del cual insertara: "; cin >> datoRef;
    
        insertarAntesDeElemento(dato, datoRef);

        cout<< endl<< endl<< "Si desea ingresar mas datos presione 1, para terminar presione 0."<< endl;
        cin >> otra;
        
    } while (otra != 0);
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
    int opcion = 0;

    cout<< "Lista de numeros: " << endl;

    do
    {
        cout << "ELIGA UNA DE LAS SIGUIENTESS OPCIONES AL PRESIONAR EL NUMERO CORRESPONDIENTE" << endl;
        cout << "1. Insertar datos en la lista" << endl;
        cout << "2. Mostrar Lista" << endl;
        cout << "3. Buscar dato en la lista (si existe o no)" << endl;
        cout << "4. Suma y promedio de los datos de la lista" << endl;
        cout << "5. Salir" << endl;

        cin >> opcion;

        cout << endl;

        switch (opcion)
        {
        case 1:
            objListaDoble.insertarEnLista();
            break;
        case 2:
            objListaDoble.mostrarLista();
            break;
        case 3:
            cin.clear();
            int datoB;
            cout << "Que dato desea buscar? ";
            cin >> datoB;
            objListaDoble.buscarRec(datoB);
            break;
        case 4:
            objListaDoble.sumaypromedio();
            cout << endl;
            break;
        }
    } while (opcion != 5);
    
    return 0;
}
