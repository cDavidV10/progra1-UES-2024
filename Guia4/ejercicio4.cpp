// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>
#include <stdlib.h>

const int size = 5;

using std::cin;
using std::cout;
using std::endl;

bool esNumero(char);
bool esBisiesto(int);
bool validacionFormato(char[]);
bool validacionFecha(int, int, int);
void imprimir(char[size][11]);
void ordenar(char[size][11], int[]);
const int indice = 5;

int main(int argc, char const *argv[])
{
    char fechas[size][11];
    int valorFecha[size], dia, mes, anio;
    bool formatoCorrecto = false, fechaCorrecta = false;

    cout << "Digite sus fechas en el formato dd/MM/yyyy" << endl;
    for (int i = 0; i < size; i++)
    {
        do
        {
            cout << "Digite su fecha " << i + 1 << ": ";
            cin.getline(fechas[i], 11);

            formatoCorrecto = validacionFormato(fechas[i]);

            dia = atoi(fechas[i]);
            mes = atoi(fechas[i] + 3);
            anio = atoi(fechas[i] + 6);

            fechaCorrecta = validacionFecha(dia, mes, anio);
            if (!formatoCorrecto || !fechaCorrecta)
            {
                cout << "Formato o fecha incorrecta. Intente nuevamente." << endl;
            }

        } while (!formatoCorrecto || !fechaCorrecta);

        valorFecha[i] = anio * 10000 + mes * 100 + dia;
    }

    ordenar(fechas, valorFecha);
    cout << "Gracias por usar nuestro sistema :)";
    return 0;
}

bool esNumero(char numero)
{
    return (numero >= '0' && numero <= '9');
}

bool esBisiesto(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

bool validacionFormato(char fecha[])
{
    if (strlen(fecha) == 10 && fecha[2] == '/' && fecha[5] == '/' &&
        esNumero(fecha[0]) && esNumero(fecha[1]) &&
        esNumero(fecha[3]) && esNumero(fecha[4]) &&
        esNumero(fecha[6]) && esNumero(fecha[7]) &&
        esNumero(fecha[8]) && esNumero(fecha[9]))
    {
        return true;
    }

    return false;
}

bool validacionFecha(int dia, int mes, int anio)
{
    int limite;

    if (mes < 1 || mes > 12)
    {
        return false;
    }

    switch (mes)
    {
    case 2:
        limite = esBisiesto(anio) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        limite = 30;
        break;
    default:
        limite = 31;
        break;
    }

    if (dia < 1 || dia > limite)
    {
        return false;
    }

    return true;
}

void imprimir(char fechas[size][11])
{
    for (int i = 0; i < size; i++)
    {
        cout << fechas[i] << endl;
    }
}

void ordenar(char fechas[size][11], int valor[])
{
    char aux[11];
    int auxVal;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (valor[j] > valor[j + 1])
            {
                auxVal = valor[j];
                valor[j] = valor[j + 1];
                valor[j + 1] = auxVal;

                strcpy(aux, fechas[j]);
                strcpy(fechas[j], fechas[j + 1]);
                strcpy(fechas[j + 1], aux);
            }
        }
    }

    cout << "Fechas ordenadas de forma ascendente:" << endl;
    imprimir(fechas);

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (valor[j] < valor[j + 1])
            {
                auxVal = valor[j + 1];
                valor[j + 1] = valor[j];
                valor[j] = auxVal;

                strcpy(aux, fechas[j + 1]);
                strcpy(fechas[j + 1], fechas[j]);
                strcpy(fechas[j], aux);
            }
        }
    }

    cout << "Fechas ordenadas de forma descendetes son:" << endl;
    imprimir(fechas);
}
