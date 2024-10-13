// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <math.h>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

void llenarVector(int[]);
void buscar(int[], int);
int cercano(int[], int);
int leer();

int main(int argc, char const *argv[])
{
    int numeros[5], aux;

    cout << "Ingrese 5 numeros" << endl;

    llenarVector(numeros);

    cout << "Ingrese un numero para buscar: ";
    aux = leer();

    buscar(numeros, aux);

    cout << "Vector inverso: " << endl;

    for (int i = 4; i >= 0; i--)
    {
        cout << numeros[i] << " ";
    }

    return 0;
}

void llenarVector(int numeros[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese su numero " << i + 1 << ": ";
        numeros[i] = leer();
    }
}

int leer()
{
    int numero;

    while (true)
    {
        cin >> numero;

        if (cin.fail())
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

int cercano(int numeros[], int buscar)
{
    int menor = abs(buscar - numeros[0]);
    int auxiliar = numeros[0];
    for (int i = 0; i < 5; i++)
    {
        if (abs(buscar - numeros[i]) < menor)
        {
            menor = abs(buscar - numeros[i]);
            auxiliar = numeros[i];
        }
    }
    return auxiliar;
}

void buscar(int numeros[], int buscar)
{
    bool existe;
    int numero;
    for (int i = 0; i < 5; i++)
    {
        existe = false;
        if (numeros[i] == buscar)
        {
            existe = true;
            numero = numeros[i];
            break;
        }
    }

    if (existe)
    {
        cout << "El numero existe" << endl;
        cout << "El numero es: " << numero << endl;
    }
    else
    {
        cout << "El nunero no existe" << endl;
        numero = cercano(numeros, buscar);
        cout << "El numero mas cercano es: " << numero << endl;
    }
}
