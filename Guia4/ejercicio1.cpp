// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

const int size = 5;

using std::cin;
using std::cout;
using std::endl;

void imprimir(char[size][20], float[]);
void ordenamientoBurbuja(char[size][20], float[]);

int main(int argc, char const *argv[])
{
    char estudiantes[size][20] = {"Manuel", "Leslie", "Franco", "Ernesto", "Amrmando"};
    float notas[size] = {6, 7, 3, 8, 9};

    imprimir(estudiantes, notas);
    cout << "Estudiantes ordenados por nombre" << endl;

    ordenamientoBurbuja(estudiantes, notas);
    imprimir(estudiantes, notas);

    cout << "Gracias por usar nuestro sistema :)";

    return 0;
}

void ordenamientoBurbuja(char datos[size][20], float nota[size])
{
    char aux[20];
    float auxNota;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - (i + 1); j++)
        {
            if (strcmp(datos[j], datos[j + 1]) > 0)
            {
                strcpy(aux, datos[j]);
                strcpy(datos[j], datos[j + 1]);
                strcpy(datos[j + 1], aux);

                auxNota = nota[j];
                nota[j] = nota[j + 1];
                nota[j + 1] = auxNota;
            }
        }
    }
}

void imprimir(char datos[size][20], float notas[size])
{
    for (int i = 0; i < size; i++)
    {
        cout << datos[i] << "\tNota: " << notas[i] << endl;
    }
}