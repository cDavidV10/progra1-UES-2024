// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

bool invertir(char cadena[]);

int main()
{
    char frase[50];

    cout << "Determinar si su frase es un palindromo" << endl;
    cout << "Ingrese la frase: ";
    gets(frase);

    if (invertir(frase))
    {
        cout << "Es un palindromo";
    }
    else
    {
        cout << "No es un palindromo";
    }
    return 0;
}

bool invertir(char cadena[])
{
    char auxiliar[50];
    int contador = 0;

    for (int i = strlen(cadena) - 1; i >= 0; i--)
    {
        auxiliar[contador] = cadena[i];
        contador++;
    }

    for (int i = 0; i < strlen(cadena); i++)
    {
        if (auxiliar[0] != ' ')
        {
            if (auxiliar[i] == cadena[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
