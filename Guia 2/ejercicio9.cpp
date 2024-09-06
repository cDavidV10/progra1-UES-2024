// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

void invertir(char cadena[]);

int main()
{
    char frase[50];

    cout << "Programa para inverir cadenas" << endl;
    cout << "Ingrese la frase: ";
    gets(frase);

    invertir(frase);

    cout << "Frase inverida: " << frase;
    return 0;
}

void invertir(char cadena[])
{
    char auxiliar[50];
    int contador = 0;

    for (int i = strlen(cadena) - 1; i >= 0; i--)
    {
        auxiliar[contador] = cadena[i];
        contador++;
    }

    auxiliar[strlen(cadena)] = '\0';

    strcpy(cadena, auxiliar);
}
