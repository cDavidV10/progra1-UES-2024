// Carlos David Vásquez Rivas VR24001

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int divisoresA[50], divisoresB[50];

bool isAmigos(int, int);
const int e = 2.718281828;

int contA = 0, contB = 0;

int main()
{

    double numero;
    int num, mult = 1, div1 = 0, div2 = 0, num2, opcion, suma1 = 0, suma2 = 0;
    cout << "*************Menu***********" << endl;
    cout << "1.Factorial de un numero" << endl;
    cout << "2.Numero e" << endl;
    cout << "3.Dos numeros son amigos" << endl;
    cout << "4.Salir" << endl;
    cin >> opcion;

    switch (opcion)
    {

    case 1:

        cout << "Ingrese un numero: ";
        cin >> num;
        for (int i = num; i >= 1; i--)
        {
            mult *= i;
        }
        cout << "\nEl factorial del numero: " << num << " es " << mult;
        break;

    case 2:

        cout << "Ingresa un numero: ";
        cin >> num;
        // cout.precision(3);
        numero = pow(e, num);
        cout << "\nEl numero euler es: " << numero;
        break;

    case 3:

        int a, b;
        cout << "Ingrese el primer numero: ";
        cin >> a;
        cout << "\nIngrese el segundo numero: ";
        cin >> b;
        cout << "\n~\n";

        if (isAmigos(a, b))
        {
            cout << "\n Son numeros amigos\n";
        }

        else
        {
            cout << "\n No son numeros amigos\n";
        }

        cout << "\n Divisores de " << a << ": ";

        for (int i = 0; i < contA; i++)
        {
            cout << divisoresA[i] << " ";
        }

        cout << "\n\n Divisores " << b << ": ";

        for (int i = 0; i < contB; i++)
        {
            cout << divisoresB[i] << " ";
        }


    case 4:

        return 0;

    default:
        cout << "\nError, el numero que registraste no esta en el sistema\n";
    }

    return 0;
}

bool isAmigos(int a, int b)
{
    int divisorA = 0, divisorB = 0;

    for (int i = 1; i < a; i++) // recorre todos los numeros menores a "a"
    {
        if (a % i == 0) // divisores exactos
        {
            divisoresA[contA] = i;   // Almacena los divisores
            divisorA = divisorA + i; // Acumula la sumatoria
            contA++;
        }
    }
    for (int i = 1; i < b; i++) // recorre todos los numeros menores a "a"
    {
        if (b % i == 0) // divisores exactos
        {
            divisoresB[contB] = i;   // Almacena los divisores
            divisorB = divisorB + i; // Acumula la sumatoria
            contB++;
        }
    }

    if (a == divisorB && b == divisorA)
    {
        return true;
    }
    else
    {
        return false;
    }
}