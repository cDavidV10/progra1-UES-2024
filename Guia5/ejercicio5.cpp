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
int indice = 0;
int opcion = 0;

struct Corredor
{
    string nombre;
    int edad;
    char sexo;
    string club;
    string categoria;
} corredor;

void llenado();
void imprimir();
int leer();
void validaciones();
void gotoxy(int, int);

int main(int argc, char const *argv[])
{

    Corredor corredor;

    cout << "Registro de corredores" << endl;

    llenado();
    imprimir();

    return 0;
}

void llenado()
{
    char sexoInput;
    do
    {
        cout << "Nombre: ";
        getline(cin, corredor.nombre);
    } while (corredor.nombre == "");

    do
    {
        cout << "Club: ";
        getline(cin, corredor.club);
    } while (corredor.club == "");

    cout << "Edad: ";
    corredor.edad = leer();

    cin.ignore();

    do
    {
        cout << "Sexo (f/m): ";
        cin >> sexoInput;
        sexoInput = toupper(sexoInput);
    } while (sexoInput != 'F' && sexoInput != 'M');
    corredor.sexo = sexoInput;

    if (corredor.edad <= 18)
    {
        corredor.categoria = "Juvenil";
    }

    if (corredor.edad > 18 && corredor.edad <= 40)
    {
        corredor.categoria = "Senior";
    }

    if (corredor.edad > 40)
    {
        corredor.categoria = "Veterano";
    }

    system("Pause");
}

void imprimir()
{
    system("cls");
    gotoxy(15, 0);
    cout << "Datos del corredor";
    gotoxy(0, 1);
    cout << "Nombre";
    gotoxy(15, 1);
    cout << "Edad";
    gotoxy(25, 1);
    cout << "Sexo";
    gotoxy(35, 1);
    cout << "Club";
    gotoxy(50, 1);
    cout << "Categoria";

    gotoxy(0, 2);
    cout << corredor.nombre;
    gotoxy(15, 2);
    cout << corredor.edad;
    gotoxy(25, 2);
    cout << corredor.sexo;
    gotoxy(35, 2);
    cout << corredor.club;
    gotoxy(50, 2);
    cout << corredor.categoria;
}

int leer()
{
    int numero;

    while (true)
    {
        cin >> numero;

        if (cin.fail() || numero <= 0)
        {
            validaciones();
        }
        else
        {
            break;
        }
    }
    return numero;
}

void validaciones()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Dato incorrecto, ingrese nuevamente: ";
}

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hcon, coord);
}
