// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>
#include <ctime>
#include <limits>

const int size = 20;

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

int obtenerNumeroAleatorio(int, int);
int leer();
void ordenar();
void imprimir();

int numeros[size];

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int minimo = 0, maximo = 0;

    cout << "Ingrese numeros entre 0 y 100" << endl;

    cout << "Ingrese el valor minimo: ";
    minimo = leer();

    cout << "Ingrese el valor maximo: ";
    maximo = leer();

    for (int i = 0; i < size; i++)
    {
        numeros[i] = obtenerNumeroAleatorio(minimo, maximo);
    }

    cout << "Los numeros generados son:" << endl;
    imprimir();
    ordenar();

    cout << "\nNumero minimo: " << minimo << endl;
    cout << "Numero maximo: " << maximo << endl;
    cout << "Los numeros ordenados son:" << endl;
    imprimir();

    cout << "\nGracias por usar nuestro sistema :)";
    return 0;
}

int obtenerNumeroAleatorio(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int leer()
{
    int numero;

    while (true)
    {
        cin >> numero;
        if (cin.fail() || numero < 0 || numero > 100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Dato Incorrecto, ingrese el dato nuevamente: ";
        }
        else
        {
            break;
        }
    }
    return numero;
}

//* Ordenar Inserccion;
void ordenar()
{
    int auxiliar = 0;
    int pos = 0;
    for (int i = 0; i < size; i++)
    {
        pos = i;
        auxiliar = numeros[i];

        while (pos > 0 && auxiliar < numeros[pos - 1])
        {
            numeros[pos] = numeros[pos - 1];
            pos--;
        }

        numeros[pos] = auxiliar;
    }
}

void imprimir()
{
    for (int i = 0; i < size; i++)
    {
        cout << numeros[i] << "\t";
    }
}
