// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char cadena[50], letras[6] = "aeiou";
    bool esvocal;
    int vocales = 0, consonante = 0;

    cout << "\t\t\t\t Programa que cuenta vocales y consonantes" << endl;
    cout << "Ingrese cadena: ";
    gets(cadena);

    for (int i = 0; i < strlen(cadena); i++)
    {
        if (cadena[i] != ' ')
        {
            esvocal = false;
            for (int j = 0; j < strlen(letras); j++)
            {
                if (cadena[i] == letras[j])
                {
                    vocales++;
                    esvocal = true;
                    break;
                }
            }

            if (!esvocal)
            {
                consonante++;
            }
        }
    }

    cout << "Consonantes: " << consonante << " Vocales: " << vocales << endl;

    return 0;
}
