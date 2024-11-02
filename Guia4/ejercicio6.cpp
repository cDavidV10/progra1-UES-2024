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

//* Ordenar Insercion
void ordenar(char cadena[])
{
    char aux;
    int pos;

    for (int i = 0; i < strlen(cadena); i++)
    {
        pos = i;
        aux = cadena[i];

        while (pos > 0 && aux < cadena[pos - 1])
        {
            cadena[pos] = cadena[pos - 1];
            pos--;
        }

        cadena[pos] = aux;
    }
}
