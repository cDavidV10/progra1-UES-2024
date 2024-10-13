// Carlos David Vásquez Rivas   VR24001

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void llenarVector(int[]);
int main(int argc, char const *argv[])
{
    int numeros[10], suma = 0, pares = 0, impares = 0, multiplicacion = 1;

    cout << "Ingrese 10 numeros" << endl;

    llenarVector(numeros);

    for (int i = 0; i < 10; i++)
    {
        if (numeros[i] % 2 == 0)
        {
            pares++;
            suma += numeros[i];
        }
        else
        {
            impares++;
            multiplicacion *= numeros[i];
        }
    }

    if (impares == 0)
    {
        multiplicacion = 0;
    }

    cout << "Cantidad de pares: " << pares << endl;
    cout << "Suma de pares: " << suma << endl;
    cout << "Cantidad de impares: " << impares << endl;
    cout << "Multiplicacion de impares: " << multiplicacion;

    return 0;
}

void llenarVector(int numeros[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese su numero " << i + 1 << ": ";
        cin >> numeros[i];
    }
}
