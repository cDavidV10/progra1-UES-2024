//  Carlos David Vásquez Rivas  VR24001

#include <iostream>
#include <limits>
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;

const int size = 200;
int opcion = 0, cantidadHijos = 0;

struct Hijos
{
    string nombre;
    int edad;
};

struct Datos
{
    string nombre;
    int edad;
    string conyugue;
    struct Hijos hijos[size];
} madre;

int leer();
void imprimir();
void gotoxy(int, int);

int main(int argc, char const *argv[])
{
    cout << "Registro familiar" << endl;

    do
    {
        cout << "Nombre de la madre: ";
        getline(cin, madre.nombre);
    } while (madre.nombre == "");

    cout << "Edad: ";
    madre.edad = leer();

    cin.ignore();

    do
    {
        cout << "Nombre del conyugue: ";
        getline(cin, madre.conyugue);
    } while (madre.conyugue == "");

    cout << "Cantidad de hijos: ";
    cantidadHijos = leer();

    if (cantidadHijos != 0)
    {
        cout << "Datos de los hijos" << endl;

        for (int i = 0; i < cantidadHijos; i++)
        {
            cin.ignore();
            do
            {
                cout << "Nombre: ";
                getline(cin, madre.hijos[i].nombre);
            } while (madre.hijos[i].nombre == "");

            cout << "Edad: ";
            madre.hijos[i].edad = leer();
        }
    }

    imprimir();
    return 0;
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
            cout << "Dato incorrecto, ingrese nuevamente: ";
        }
        else
        {
            break;
        }
    }
    return numero;
}

void imprimir()
{
    system("cls");
    gotoxy(20, 0);
    cout << "Datos de la madre";
    gotoxy(0, 1);
    cout << "Nombre";
    gotoxy(20, 1);
    cout << "Edad";
    gotoxy(30, 1);
    cout << "Conyugue";
    gotoxy(0, 2);
    cout << madre.nombre;
    gotoxy(20, 2);
    cout << madre.edad;
    gotoxy(30, 2);
    cout << madre.conyugue;

    if (cantidadHijos != 0)
    {
        gotoxy(20, 3);
        cout << "Datos de los hijos";
        gotoxy(0, 4);
        cout << "Nombre";
        gotoxy(20, 4);
        cout << "Edad";

        for (int i = 0; i < cantidadHijos; i++)
        {
            gotoxy(0, i + 5);
            cout << madre.hijos[i].nombre;
            gotoxy(20, i + 5);
            cout << madre.hijos[i].edad;
        }
    }
}

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hcon, coord);
}