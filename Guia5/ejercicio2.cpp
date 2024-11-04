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
int indice = 0, opcion = 0;

struct Platillos
{
    string nombre;
    float precio;
    string tipo;
};

void menu();
void add(Platillos[]);
void imprimir(Platillos[]);
int leer();
float leerPlatillo();
void gotoxy(int, int);

int main(int argc, char const *argv[])
{
    Platillos platillo[size];

    do
    {
        menu();

        switch (opcion)
        {
        case 1:
            add(platillo);
            break;
        case 2:
            imprimir(platillo);
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
    system("cls");
    cout << "*****   LOS TRES CERDITOS   *****" << endl;
    cout << "1. Agregar Platillo" << endl;
    cout << "2. Mostrar Platillo" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion del menu: ";
    opcion = leer();
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

float leerPlatillo()
{
    float numero;

    while (true)
    {
        cin >> numero;
        if (cin.fail() || numero <= 0)
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

void add(Platillos platillo[])
{
    system("cls");
    cin.ignore();
    do
    {
        cout << "Nombre del platillo: ";
        getline(cin, platillo[indice].nombre);
    } while (platillo[indice].nombre == "");

    cout << "Precio del platillo: $";
    platillo[indice].precio = leerPlatillo();

    cin.ignore();
    do
    {
        cout << "Tipo de platillo: ";
        getline(cin, platillo[indice].tipo);
    } while (platillo[indice].tipo == "");

    indice++;
    system("pause");
}

void imprimir(Platillos platillo[])
{
    system("cls");

    if (indice == 0)
    {
        cout << "No hay platillos" << endl;
    }
    else
    {
        gotoxy(20, 0);
        cout << "Lista de Platillos";
        gotoxy(0, 1);
        cout << "Nombre platillo";
        gotoxy(40, 1);
        cout << "Precio";
        gotoxy(55, 1);
        cout << "Tipo de platillo";

        for (int i = 0; i < indice; i++)
        {
            gotoxy(0, i + 2);
            cout << platillo[i].nombre;
            gotoxy(40, i + 2);
            cout << "$" << platillo[i].precio;
            gotoxy(55, i + 2);
            cout << platillo[i].tipo;
        }
    }
    cout << endl;
    system("pause");
}

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hcon, coord);
}
