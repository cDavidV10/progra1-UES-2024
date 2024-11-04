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

struct Estudiantes
{
    string carnet;
    char sexo;
    int edad;
    float notas[3];
    float promedio;
} estudiante[size];

void menu();
void add();
void imprimir();
int leer();
float validarNota();
void validaciones();
void gotoxy(int, int);

int main(int argc, char const *argv[])
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

    cout << "Gracias por usar nuestro sistema :)";
    return 0;
}

void menu()
{
    system("cls");
    cout << "1. Agregar" << endl;
    cout << "2. Mostrar" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese una opcion del menu: ";
    opcion = leer();
}

void add()
{
    char sexoInput;
    float promedio = 0;
    system("cls");
    cin.ignore();
    cout << "AGREGAR ESTUDIANTE" << endl;
    do
    {
        cout << "Carnet: ";
        getline(cin, estudiante[indice].carnet);
    } while (estudiante[indice].carnet == "");

    do
    {
        cout << "Sexo (f/m): ";
        cin >> sexoInput;
        sexoInput = toupper(sexoInput);
    } while (sexoInput != 'F' && sexoInput != 'M');
    estudiante[indice].sexo = sexoInput;
    cout << "Edad: ";
    estudiante[indice].edad = leer();

    cout << "Ingresar notas" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Nota " << i + 1 << ": ";
        estudiante[indice].notas[i] = validarNota();
    }

    //? Calcular el promedio
    for (int i = 0; i < 3; i++)
    {
        promedio += estudiante[indice].notas[i];
    }

    promedio /= 3;

    estudiante[indice].promedio = promedio;

    indice++;
    system("pause");
}

void imprimir()
{
    system("cls");
    if (indice == 0)
    {
        cout << "No hay estudiantes registrados";
    }
    else
    {
        gotoxy(15, 0);
        cout << "Lista de Estudiantes";
        gotoxy(0, 1);
        cout << "Carnet";
        gotoxy(15, 1);
        cout << "Edad";
        gotoxy(25, 1);
        cout << "Sexo";
        gotoxy(35, 1);
        cout << "Promedio";

        for (int i = 0; i < indice; i++)
        {
            gotoxy(0, i + 2);
            cout << estudiante[i].carnet;
            gotoxy(15, i + 2);
            cout << estudiante[i].edad;
            gotoxy(25, i + 2);
            cout << estudiante[i].sexo;
            gotoxy(35, i + 2);
            cout << estudiante[i].promedio;
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

float validarNota()
{
    float numero;

    while (true)
    {
        cin >> numero;

        if (cin.fail() || numero < 0 || numero > 10)
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
