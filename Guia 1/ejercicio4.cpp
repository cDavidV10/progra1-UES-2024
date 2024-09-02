// Carlos David Vásquez Rivas VR24001

#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

bool PRIMO(int);
unsigned long long FACTORIAL(int);
void MULTIPLO(int);

int main(int argc, char const *argv[])
{
    int numeros[100], index = 0;
    unsigned long long factorial;
    char respuesta;
    bool esprimo;

    do
    {
        system("cls");
        cout << "Ingrese un numero: ";
        cin >> numeros[index];
        index++;

        cin.ignore();
        cout << "Desea continuar (s/n): ";
        cin.get(respuesta);
        cin.ignore();
    } while (respuesta == 's' || respuesta == 'S');

    for (int i = 0; i < index; i++)
    {
        esprimo = PRIMO(numeros[i]);

        if (esprimo)
        {
            cout << numeros[i] << " es primo " << endl;
            factorial = FACTORIAL(numeros[i]);
            cout << "Su factorial es: " << factorial << endl;
        }
        else
        {
            cout << numeros[i] << " no es primo " << endl;
            cout << "Multiplos menorea: ";
            MULTIPLO(numeros[i]);
            cout << "\n";
        }
    }

    return 0;
}

bool PRIMO(int numero)
{
    if (numero <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(numero); i++)
    {
        if (numero % i == 0)
        {
            return false;
        }
    }

    return true;
}

unsigned long long FACTORIAL(int numero)
{
    unsigned long long factorial = 1;
    ;
    for (int i = 1; i <= numero; i++)
    {
        factorial *= i;
    }

    return factorial;
}

void MULTIPLO(int numero)
{
    for (int i = 1; i < numero; i++)
    {
        int resultado = numero * i;
        if (resultado <= numero)
        {
            cout << resultado << " ";
        }
    }
}
