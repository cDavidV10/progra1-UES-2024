// Carlos David Vásquez Rivas VR24001

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int divisoresA[50], divisoresB[50];

bool isAmigos(int, int);

int contA = 0, contB = 0;

int main()
{
    int a, b;
    cout << "Programa para determinar numeros amigos" << endl;
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;
    if (isAmigos(a, b))
    {
        cout << "Son numeros amigos\n";
    }
    else
    {
        cout << "No son numeros amigos\n";
    }

    cout << "Divisores de " << a << ": ";

    for (int i = 0; i < contA; i++)
    {
        cout << divisoresA[i] << " ";
    }

    cout << "Divisores " << b << ": ";

    for (int i = 0; i < contB; i++)
    {
        cout << divisoresB[i] << " ";
    }

    return 0;
}

bool isAmigos(int a, int b)
{
    int divisorA = 0, divisorB = 0;

    for (int i = 1; i < a; i++)
    {
        if (a % i == 0)
        {
            divisoresA[contA] = i;
            divisorA = divisorA + i;
            contA++;
        }
    }
    for (int i = 1; i < b; i++)
    {
        if (b % i == 0)
        {
            divisoresB[contB] = i;
            divisorB = divisorB + i;
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