// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void eliminarVocales(char[], char[]);
void eliminarConsonantes(char[], char[]);
void mostrarNumeros(char[], char[]);

int main()
{
    char cadena[200], letras[6] = "aeiou", numeros[11] = "0123456789";
    int opcion;

    cout << "Digite su texto: ";
    cin.getline(cadena, 100, '\n');

    cout << "Que desea hacer con su texto: " << endl;
    cout << "1.Eliminar las vocales" << endl;
    cout << "2.Eliminar las consonantes" << endl;
    cout << "3.Mostrar solo los numeros" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        eliminarVocales(cadena, letras);
        break;
    case 2:
        eliminarConsonantes(cadena, letras);
        break;
    case 3:
        mostrarNumeros(cadena, numeros);
        break;

    default:
        cout << "La opcion ingresada no esta en nuestro sistema" << endl;
        break;
    }
    return 0;
}

void eliminarVocales(char cadena[], char letras[])
{
    char salida[200];
    bool vocal;

    for (int i = 0; i < strlen(cadena); i++)
    {
        vocal = false;
        for (int j = 0; j < strlen(letras); j++)
        {
            if (cadena[i] == letras[j])
            {
                vocal = true;
                break;
            }
        }
        if (!vocal)
        {

            salida[i] = cadena[i];
        }
        else
        {
            salida[i] = ' ';
        }
    }

    salida[strlen(cadena)] = '\0';
    cout << salida;
}

void eliminarConsonantes(char cadena[], char letras[])
{
    char salida[200];
    bool consonante, esVocal;

    for (int i = 0; i < strlen(cadena); i++)
    {
        consonante = true;
        esVocal = false;

        // Verificamos si es una vocal
        for (int j = 0; j < strlen(letras); j++)
        {
            if (cadena[i] == letras[j])
            {
                esVocal = true;
                consonante = false;
                break;
            }
        }

        if (!esVocal && (cadena[i] < '0' || cadena[i] > '9'))
        {
            consonante = true;
        }
        else
        {
            consonante = false;
        }

        if (!consonante)
        {
            salida[i] = cadena[i];
        }
        else
        {
            salida[i] = ' ';
        }
    }

    salida[strlen(cadena)] = '\0';
    cout << salida;
}

void mostrarNumeros(char cadena[], char numeros[])
{
    char salida[200];
    bool esNumero, hayNumeros = false;

    for (int i = 0; i < strlen(cadena); i++)
    {
        esNumero = false;
        for (int j = 0; j < strlen(numeros); j++)
        {
            if (cadena[i] == numeros[j])
            {
                esNumero = true;
                break;
            }
        }

        if (esNumero)
        {

            salida[i] = cadena[i];
        }
        else
        {
            salida[i] = ' ';
        }
    }

    for (int i = 0; i < strlen(cadena); i++)
    {
        for (int j = 0; j < strlen(numeros); j++)
        {
            if (cadena[i] == numeros[j])
            {
                hayNumeros = true;
                break;
            }
        }
    }

    salida[strlen(cadena)] = '\0';
    if (hayNumeros)
    {

        cout << salida;
    }
    else
    {
        cout << "No hay numeros";
    }
}
