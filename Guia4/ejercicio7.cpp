// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <limits>

const int size = 5;

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

int opcion = 0;

void menu();
int leer();
bool esNumero(char);
bool esBisiesto(int);
bool validacionFormato(char[]);
bool validacionFecha(int, int, int);
void imprimir(char[size][11], int[]);
void ordenarFechas(char[size][11], int[], int[]);
void ordenarMinutos(char[size][11], int[]);
const int indice = 5;

int main(int argc, char const *argv[])
{
    char fechas[size][11];
    int valorFecha[size], entrenamiento[size], dia, mes, anio;
    bool formatoCorrecto = false, fechaCorrecta = false;

    cout << "Digite sus fechas en el formato dd/MM/yyyy" << endl;
    for (int i = 0; i < size; i++)
    {
        fflush(stdin);
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

        cout << "Ingrese los minutos de entrenamineto: ";
        entrenamiento[i] = leer();
        valorFecha[i] = anio * 10000 + mes * 100 + dia;
    }

    do
    {
        system("cls");
        menu();
        switch (opcion)
        {
        case 1:
            ordenarFechas(fechas, valorFecha, entrenamiento);
            imprimir(fechas, entrenamiento);
            cout << "Presione una tecla para continuar";
            system("pause>null");
            break;
        case 2:
            ordenarMinutos(fechas, entrenamiento);
            imprimir(fechas, entrenamiento);
            cout << "Presione una tecla para continuar";
            system("pause>null");
            break;

        default:
            break;
        }
    } while (opcion != 3);

    cout << "Gracias por usar nuestro sistema :)";

    return 0;
}

void menu()
{
    cout << "Ordenar fechas por:" << endl;
    cout << "1. fecha" << endl;
    cout << "2. Minutos de entrenamiento" << endl;
    cout << "3. salir" << endl;
    cout << "Seleccione una opcion del menu: ";
    opcion = leer();
}

int leer()
{
    int numero;

    while (true)
    {
        cin >> numero;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Dato Incorrecto, ingrese el dato nuevamente: ";
        }
        else
        {
            break;
        }
    }
    return numero;
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

void imprimir(char fechas[size][11], int minutos[])
{
    for (int i = 0; i < size; i++)
    {
        cout << "La fecha " << fechas[i] << " entreno " << minutos[i] << " minutos" << endl;
    }
}

void ordenarFechas(char fechas[size][11], int valor[], int minutos[])
{
    char aux[11];
    int auxVal, auxMinutos;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (valor[j] > valor[j + 1])
            {
                auxVal = valor[j];
                valor[j] = valor[j + 1];
                valor[j + 1] = auxVal;

                auxMinutos = minutos[j];
                minutos[j] = minutos[j + 1];
                minutos[j + 1] = auxMinutos;

                strcpy(aux, fechas[j]);
                strcpy(fechas[j], fechas[j + 1]);
                strcpy(fechas[j + 1], aux);
            }
        }
    }
}

void ordenarMinutos(char fechas[size][11], int minutos[])
{
    char aux[11];
    int auxMinutos;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (minutos[j] > minutos[j + 1])
            {
                auxMinutos = minutos[j];
                minutos[j] = minutos[j + 1];
                minutos[j + 1] = auxMinutos;

                strcpy(aux, fechas[j]);
                strcpy(fechas[j], fechas[j + 1]);
                strcpy(fechas[j + 1], aux);
            }
        }
    }
}
