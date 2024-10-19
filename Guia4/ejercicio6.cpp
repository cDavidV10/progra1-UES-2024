// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int size = 100;
char cadena[size], cadenaOrden[size];

void ordenar(char[]);

int main(int argc, char const *argv[])
{

    char *aux;

    cout << "Ingrese su palabra: ";
    cin.getline(cadena, size);

    aux = strtok(cadena, " ");

    while (aux != NULL)
    {
        ordenar(aux);
        strcat(cadenaOrden, aux);
        strcat(cadenaOrden, " ");
        aux = strtok(NULL, " ");
    }

    cout << "Su palabra ordenada por letras es: " << cadenaOrden << endl;
    cout << "Gracias por usar nuestro sistema :)";

    return 0;
}

void ordenar(char cadena[])
{
    char aux;

    for (int i = 0; i < strlen(cadena) - 1; i++)
    {
        for (int j = 0; j < strlen(cadena) - (i + 1); j++)
        {
            if (cadena[j] > cadena[j + 1])
            {
                aux = cadena[j];
                cadena[j] = cadena[j + 1];
                cadena[j + 1] = aux;
            }
        }
    }
}
