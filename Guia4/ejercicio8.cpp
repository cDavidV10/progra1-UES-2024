// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int size = 100;
char cadena[size], cadenaOrden[size][size], salida[size];
int index = 0;

void ordenar(char[size][size]);

int main(int argc, char const *argv[])
{

    char *aux;

    cout << "Ingrese su palabra: ";
    cin.getline(cadena, size);

    aux = strtok(cadena, " ");

    while (aux != NULL)
    {
        strcpy(cadenaOrden[index], aux);
        index++;
        aux = strtok(NULL, " ");
    }

    ordenar(cadenaOrden);

    salida[0] = '\0';
    for (int i = 0; i < index; i++)
    {
        strcat(salida, cadenaOrden[i]);
        strcat(salida, " ");
    }

    cout << "Su palabra ordenada por letras es: " << salida << endl;
    cout << "Gracias por usar nuestro sistema :)";

    return 0;
}

void ordenar(char cadena[size][size])
{
    char aux[size];

    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - (i + 1); j++)
        {
            if (strcmp(cadena[j], cadena[j + 1]) > 0)
            {
                strcpy(aux, cadena[j]);
                strcpy(cadena[j], cadena[j + 1]);
                strcpy(cadena[j + 1], aux);
            }
        }
    }
}
