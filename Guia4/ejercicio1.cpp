// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

const int size = 5;

using std::cin;
using std::cout;
using std::endl;

void imprimir(char[size][20], float[]);
void ordenamiento(char[size][20], float[]);

int main(int argc, char const *argv[])
{
    char estudiantes[size][20] = {"Manuel", "Leslie", "Franco", "Ernesto", "Armando"};
    float notas[size] = {6, 7, 3, 8, 9};

    imprimir(estudiantes, notas);
    cout << "Estudiantes ordenados por nombre" << endl;

    ordenamiento(estudiantes, notas);
    imprimir(estudiantes, notas);

    cout << "Gracias por usar nuestro sistema :)";

    return 0;
}

//* Ordenamiento insercion
void ordenamiento(char datos[size][20], float nota[size])
{
    char aux[20];
    float auxNota;
    int pos;

    for (int i = 0; i < size; i++)
    {
        pos = i;
        strcpy(aux, datos[i]);
        auxNota = nota[i];
        while (pos > 0 && strcmp(aux, datos[pos - 1]) < 0)
        {
            strcpy(datos[pos], datos[pos - 1]);
            nota[pos] = nota[pos - 1];
            pos--;
        }

        strcpy(datos[pos], aux);
        nota[pos] = auxNota;
    }
}

void imprimir(char datos[size][20], float notas[size])
{
    for (int i = 0; i < size; i++)
    {
        cout << datos[i] << "\tNota: " << notas[i] << endl;
    }
}