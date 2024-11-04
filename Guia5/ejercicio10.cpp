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

const int size = 100;
int index = 0, opcion = 0;
struct Panda
{
    string nombre;
    float peso;
    int anioNacimiento;
    char sexo;
    string fertilidad;
} pandas[size];

void menu();
void add();
float validarPeso();
int leer();
void imprimir();
void gotoxy(int, int);

int main()
{
    do
    {
        menu();

        switch (opcion)
        {
        case 1:
            add();
            break;
        case 2:
            imprimir();
            break;

        default:
            break;
        }
    } while (opcion != 3);

    cout << "Gracia por usar nuestro sistema :)";
    return 0;
}

void menu()
{
    system("cls");
    cout << "*****   PANDAS   *****" << endl;
    cout << "1. Agregar" << endl;
    cout << "2. Mostrar" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese una opcion del menu: ";
    opcion = leer();
}

void add()
{
    system("cls");
    char sexoInput;
    cin.ignore();
    do
    {
        cout << "Nombre del panda: ";
        getline(cin, pandas[index].nombre);
    } while (pandas[index].nombre == "");

    cout << "Ingrese el peso del panda (kg): ";
    pandas[index].peso = validarPeso();

    cout << "Ingrese el anio de nacimiento: ";
    pandas[index].anioNacimiento = leer();

    do
    {
        cout << "Sexo (h/m): ";
        cin >> sexoInput;
        sexoInput = toupper(sexoInput);
    } while (sexoInput != 'H' && sexoInput != 'M');
    pandas[index].sexo = sexoInput;

    pandas[index].fertilidad =
        (2024 - pandas[index].anioNacimiento) > 5 && (pandas[index].sexo == 'H') ? "si" : "no";
    index++;
}

float validarPeso()
{
    float numero;
    while (true)
    {
        cin >> numero;
        if (cin.fail() || numero <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Peso no valido. Ingrese nuevamente: ";
        }
        else
        {
            break;
        }
    }
    return numero;
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
            cout << "Dato incorrecto. Ingrese nuevamente: ";
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
    if (index == 0)
    {
        cout << "No hay registros";
    }
    else
    {
        gotoxy(20, 0);
        cout << "Informacion de los pandas";
        gotoxy(0, 1);
        cout << "Nombre";
        gotoxy(20, 1);
        cout << "Peso";
        gotoxy(30, 1);
        cout << "Nacimiento";
        gotoxy(45, 1);
        cout << "Fertilidad";

        for (int i = 0; i < index; i++)
        {
            gotoxy(0, i + 2);
            cout << pandas[i].nombre;
            gotoxy(20, i + 2);
            cout << pandas[i].peso;
            gotoxy(30, i + 2);
            cout << pandas[i].anioNacimiento;
            gotoxy(45, i + 2);
            cout << pandas[i].fertilidad;
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
