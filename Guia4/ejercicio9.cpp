// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

void ordenar(char[]);
void imprimir(char[]);
void conversor(char[]);
bool isAranama(char[], char[]);

int main(int argc, char const *argv[])
{
    char palabra1[100], palabra2[100];

    cout << "Escriba su primera palabra: ";
    cin.getline(palabra1, 100);

    cout << "Escriba su segunda palabra: ";
    cin.getline(palabra2, 100);

    conversor(palabra1);
    conversor(palabra2);

    ordenar(palabra1);
    ordenar(palabra2);

    if (isAranama(palabra1, palabra2))
    {
        cout << "Sus palabras son anagramas" << endl;
    }
    else
    {
        cout << "Sus palabras no son anagramas" << endl;
    }

    return 0;
}

//* Ordenamiento Insercion
void ordenar(char palabra[])
{
    char aux[100];
    int pos;
    for (int i = 0; i < strlen(palabra); i++)
    {
        pos = i;
        aux[i] = palabra[i];

        while (pos > 0 && aux[i] < palabra[pos - 1])
        {
            palabra[pos] = palabra[pos - 1];
            pos--;
        }

        palabra[pos] = aux[i];
    }
}

void conversor(char palabra[])
{
    for (int i = 0; i < strlen(palabra); i++)
    {
        palabra[i] = tolower(palabra[i]);
    }
}

bool isAranama(char palabra1[], char palabra2[])
{
    if (strlen(palabra1) != strlen(palabra2))
    {
        return false;
    }
    else
    {
        for (int i = 0; i < strlen(palabra1); i++)
        {
            for (int j = 0; j < strlen(palabra2) - (i + 1); j++)
            {
                if (palabra1[j] != palabra2[j])
                {
                    return false;
                }
            }
        }
    }

    return true;
}
