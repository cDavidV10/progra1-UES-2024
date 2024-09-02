// Carlos David Vásquez Rivas VR24001

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int factorial(int);

void coeficienteBinomio(int m, int n, int &binomio);

int main()
{
    int m = 0, n = 0, binomio = 0;
    cout << "**********Coeficiente de binomio*********" << endl;

    do
    {

        cout << "Ingrese m:";
        cin >> m;

        cout << "Ingrese n:";
        cin >> n;

    } while (m < 0 || n < 0);

    if (m < n || n < 0)
    {
        cout << "Error, operacion indeterminada";
    }
    else
    {
        coeficienteBinomio(m, n, binomio);
        cout << "El coeficiente del binomio es: " << binomio;
    }
    return 0;
}

void coeficienteBinomio(int m, int n, int &binomio)
{
    binomio = factorial(m) / (factorial(n) * factorial(m - n));
}

int factorial(int num)
{
    int facto = 1;

    if (num < 2)
    {
        return 1;
    }
    else
    {
        for (int i = 2; i <= num; i++)
        {
            facto = facto * i;
        }
    }

    return facto;
}