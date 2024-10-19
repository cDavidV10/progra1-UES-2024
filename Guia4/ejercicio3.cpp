// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>
#include <limits>
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;

const int size = 200;
string nombres[size];
int index = 0, opcion = 0;
int telefonos[size];

void menu();
int leer();
void add();
void ordenar();
void imprimir(string[], int[]);
void gotoxy(int x, int y);

int main(int argc, char const *argv[])
{
    do
    {
        menu();
        switch (opcion)
        {
        case 1:
            add();
            system("pause");
            break;
        case 2:
            imprimir(nombres, telefonos);
            system("pause");
            break;
        case 3:
            ordenar();
            system("pause");
            break;

        default:
            break;
        }
    } while (opcion != 4);

    cout << "Gracias por usar nuestro sistema :)";

    return 0;
}

void menu()
{
    system("cls");
    cout << "*****  MENU    *****" << endl;
    cout << "1. Agregar contancto" << endl;
    cout << "2. Ver lista de contacto" << endl;
    cout << "3. Ver lista de contacto ordenada" << endl;
    cout << "4. Salir" << endl;
    cout << "Selecione una opcion: ";
    opcion = leer();
}

void add()
{
    system("cls");
    cin.ignore();

    cout << "Agregar nuevo contacto" << endl;
    cout << "Nombre: ";
    getline(cin, nombres[index]);
    cout << "Numero de telefono sin separaciones: ";
    telefonos[index] = leer();
    index++;
}

void ordenar()
{
    string nombresOrdenados[size];
    int telefonosOrdenados[size];
    string nombreAux;
    int telAux;

    for (int i = 0; i < index; i++)
    {
        nombresOrdenados[i] = nombres[i];
        telefonosOrdenados[i] = telefonos[i];
    }

    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - (i + 1); j++)
        {
            if (nombresOrdenados[j] > nombresOrdenados[j + 1])
            {
                nombreAux = nombresOrdenados[j + 1];
                nombresOrdenados[j + 1] = nombresOrdenados[j];
                nombresOrdenados[j] = nombreAux;

                telAux = telefonosOrdenados[j + 1];
                telefonosOrdenados[j + 1] = telefonosOrdenados[j];
                telefonosOrdenados[j] = telAux;
            }
        }
    }

    imprimir(nombresOrdenados, telefonosOrdenados);
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

void imprimir(string nombre[], int telefono[])
{
    system("cls");
    if (index == 0)
    {
        cout << "No hay contanctos registrados" << endl;
    }
    else
    {
        gotoxy(10, 0);
        cout << "Lista de contacto" << endl;
        gotoxy(0, 1);
        cout << "Nombre";
        gotoxy(20, 1);
        cout << "Telefono";

        for (int i = 0; i < index; i++)
        {
            gotoxy(0, i + 2);
            cout << nombre[i];
            gotoxy(20, i + 2);
            cout << telefono[i];
        }
        cout << endl;
    }
}

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
