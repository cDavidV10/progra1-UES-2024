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

struct Materia
{
    string nombre;
    float notas[3];
    float promedio;
};

struct Estudiante
{
    string nombre;
    Materia materia[2];
    float cum;
};

const int numEstudiantes = 2;

void llenado(Estudiante[]);
void calcularPromedio(Estudiante[]);
void imprimir(Estudiante[], int);
float validar();
void gotoxy(int, int);

int main()
{
    int seleccion;
    Estudiante estudiantes[numEstudiantes];

    llenado(estudiantes);
    calcularPromedio(estudiantes);

    seleccion = -1;

    while (true)
    {
        system("cls");
        cout << "Seleccione un estudiante para ver sus datos" << endl;

        for (int i = 0; i < numEstudiantes; i++)
        {
            cout << i + 1 << ". Estudiante: " << estudiantes[i].nombre << endl;
        }
        cout << "3. Salir" << endl;

        cin >> seleccion;
        cin.ignore();

        if (seleccion < 1 || seleccion > numEstudiantes)
        {
            cout << "Intente de nuevo" << endl;
            system("pause");
        }
        else
        {
            imprimir(estudiantes, seleccion - 1);
        }
        if (seleccion == 3)
        {
            break;
        }
    }
    cout << "Gracias por usar nuestro sistema :)";
    return 0;
}

void llenado(Estudiante estudiantes[])
{
    for (int i = 0; i < numEstudiantes; i++)
    {
        system("cls");
        cout << "Ingrese el nombre del estudiante " << i + 1 << ": ";
        getline(cin, estudiantes[i].nombre);

        for (int j = 0; j < 2; j++)
        {
            cout << "Ingrese el nombre de la materia " << j + 1 << ": ";
            getline(cin, estudiantes[i].materia[j].nombre);

            for (int k = 0; k < 3; k++)
            {
                cout << "Ingrese la nota " << k + 1 << " para " << estudiantes[i].materia[j].nombre << ": ";
                estudiantes[i].materia[j].notas[k] = validar();
            }
            cin.ignore();
        }
    }
}

void calcularPromedio(Estudiante estudiantes[])
{
    float CUM;
    float sumaNotas;
    for (int i = 0; i < numEstudiantes; i++)
    {
        CUM = 0;

        for (int j = 0; j < 2; j++)
        {
            sumaNotas = 0;
            for (int k = 0; k < 3; k++)
            {
                sumaNotas += estudiantes[i].materia[j].notas[k];
            }
            estudiantes[i].materia[j].promedio = sumaNotas / 3;
            CUM += estudiantes[i].materia[j].promedio;
        }

        estudiantes[i].cum = CUM / 2;
    }
}

void imprimir(Estudiante estudiantes[], int indice)
{
    system("cls");
    gotoxy(20, 0);
    cout << "Resultados del estudiante " << estudiantes[indice].nombre << endl;
    gotoxy(0, 1);
    cout << "Materia";
    gotoxy(20, 1);
    cout << "Promedio";
    gotoxy(30, 1);
    cout << "CUM";

    for (int i = 0; i < 2; i++)
    {
        gotoxy(0, i + 2);
        cout << estudiantes[indice].materia[i].nombre;

        gotoxy(20, i + 2);
        cout << estudiantes[indice].materia[i].promedio;
    }

    gotoxy(30, 4);
    cout << estudiantes[indice].cum;
    cout << endl;

    system("pause");
}

float validar()
{
    float numero;

    while (true)
    {
        cin >> numero;

        if (cin.fail() || numero < 0 || numero > 10)
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

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hcon, coord);
}
