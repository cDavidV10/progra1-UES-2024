// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

void ordenar(char[]);
void imprimir(char[]);
bool isAranama(char[], char[]);

int main(int argc, char const *argv[])
{
    char palabra1[100], palabra2[100];

    cout << "Escriba su primera palabra: ";
    cin.getline(palabra1, 100);

    cout << "Escriba su segunda palabra: ";
    cin.getline(palabra2, 100);

    ordenar(palabra1);
    ordenar(palabra2);

    if (isAranama(palabra1, palabra2))
    {
        cout << "Sus palabras son aranamas" << endl;
    }
    else
    {
        cout << "Sus palabras no son aranamas" << endl;
    }

    return 0;
}

void ordenar(char palabra[])
{
    char aux[100];
    for (int i = 0; i < strlen(palabra); i++)
    {
        for (int j = 0; j < strlen(palabra) - (i + 1); j++)
        {
            if (palabra[j] > palabra[j + 1])
            {
                aux[j] = palabra[j];
                palabra[j] = palabra[j + 1];
                palabra[j + 1] = aux[j];
            }
        }
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
