// Carlos David Vásquez Rivas   VR24001
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    char palabra1[100], palabra2[100], auxiliar[100], salida[100] = "";

    cout << "Ingrese su primera palabra: ";
    cin.getline(palabra1, 100);

    cout << "Ingrese su segunda palabra: ";
    cin.getline(palabra2, 100);

    if (strlen(palabra1) < 5 && strlen(palabra2) < 5)
    {
        cout << "El tamanio de la primera palabra es de: " << strlen(palabra1) << endl;
        cout << "El tamanio de la segunda palabra es de: " << strlen(palabra2) << endl;

        return 0;
    }

    if (strlen(palabra1) > strlen(palabra2))
    {
        for (int i = 0; i < strlen(palabra1); i++)
        {
            auxiliar[i] = palabra1[i];
        }
        strcpy(palabra1, palabra2);
        strcpy(palabra2, auxiliar);

        cout << "Su primera palabra es: " << palabra1 << endl;
        cout << "Su segunda palabra es: " << palabra2 << endl;

        return 0;
    }

    strcat(salida, palabra1);
    strcat(salida, " y ");
    strcat(salida, palabra2);

    cout << salida;

    return 0;
}
