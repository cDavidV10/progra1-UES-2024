//  Carlos David Vásquez Rivas  VR24001

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
int opcion, indice = 0;

struct Reservaciones
{
    string nombre;
    string fechaEntrada;
    string fechaSalida;
    int numHabitacion;
};

void menu();
int leer();
void add(Reservaciones[]);
void ordenar(Reservaciones[]);
void imprimir(Reservaciones[]);
void gotoxy(int, int);

int main(int argc, char const *argv[])
{
    Reservaciones huesped[size];
    do
    {
        menu();

        switch (opcion)
        {
        case 1:
            add(huesped);
            break;
        case 2:
            ordenar(huesped);
            imprimir(huesped);
            break;

        default:
            break;
        }
    } while (opcion != 3);

    cout << "Gracias por usuar nuestro sistema :)";

    return 0;
}

void menu()
{
    system("cls");
    cout << "*****  RESGISTRO DE HUESPEDES HOTEL MASAPIONES   *****" << endl;
    cout << "1. Agregar nuevo husped" << endl;
    cout << "2. Mostrar huespedes" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion del menu: ";
    opcion = leer();
}

void add(Reservaciones huesped[])
{
    system("cls");
    cin.ignore();
    cout << "Registrar huesped" << endl;
    do
    {
        cout << "Nombre huesped: ";
        getline(cin, huesped[indice].nombre);
    } while (huesped[indice].nombre == "");

    do
    {
        cout << "Fecha de ingreso: ";
        getline(cin, huesped[indice].fechaEntrada);
    } while (huesped[indice].fechaEntrada == "");

    do
    {
        cout << "Fecha de salida: ";
        getline(cin, huesped[indice].fechaSalida);
    } while (huesped[indice].fechaSalida == "");

    cout << "Numero de habitacion: ";
    huesped[indice].numHabitacion = leer();

    indice++;
}

void ordenar(Reservaciones huesped[])
{
    Reservaciones huespedAux;
    int pos;

    for (int i = 0; i < indice; i++)
    {
        pos = i;
        huespedAux = huesped[i];

        while (pos > 0 && huespedAux.nombre < huesped[pos - 1].nombre)
        {
            huesped[pos] = huesped[pos - 1];
            pos--;
        }

        huesped[pos] = huespedAux;
    }
}

void imprimir(Reservaciones huesped[])
{
    system("cls");
    if (indice == 0)
    {
        cout << "No hay registros de huesped" << endl;
    }
    else
    {
        gotoxy(10, 0);
        cout << "REGISTRO DE HUESPEDES";
        gotoxy(0, 1);
        cout << "Nombre";
        gotoxy(15, 1);
        cout << "Fecha de entrada";
        gotoxy(35, 1);
        cout << "Fecha de salida";
        gotoxy(60, 1);
        cout << "Habitacion";

        for (int i = 0; i < indice; i++)
        {
            gotoxy(0, i + 2);
            cout << huesped[i].nombre;
            gotoxy(15, i + 2);
            cout << huesped[i].fechaEntrada;
            gotoxy(35, i + 2);
            cout << huesped[i].fechaSalida;
            gotoxy(60, i + 2);
            cout << huesped[i].numHabitacion;
        }
    }
    cout << endl;
    system("pause");
}

int leer()
{
    int numero;

    while (true)
    {
        cin >> numero;

        if (cin.fail() || numero < 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Dato incorecto, ingrese el dato nuevamente: ";
        }
        else
        {
            break;
        }
    }
    return numero;
}

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hcon, coord);
}
