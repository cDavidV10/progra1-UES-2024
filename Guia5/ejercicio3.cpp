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
int indiceMaestro = 0;
int indiceEstudiante = 0;
int opcion, subOpcion;

struct Datos
{
    string nombre;
    int edad;
};

struct Maestros
{
    struct Datos info;
    string materia;
    float salario;
} maestro[size];

struct Estudiantes
{
    struct Datos info;
    float notas[4];
    float promedio;
} estudiante[size];

void menu();
void subMenu(string);
void switchesAgregar(string);
void switchesImprimir(string);
void addMaestro();
void addEstudiante();
void imprimirMaestro();
void imprimirEstudiante();
void ordenarMaestros();
void ordenarEstudiantes();
int leer();
float validarSalario();
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
            switchesAgregar("Agregar");
            break;
        case 2:
            switchesImprimir("Imprimir");
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
    cout << "*****  MENU  *****" << endl;
    cout << "1. Agregar" << endl;
    cout << "2. Mostrar" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese una opcion del menu: ";
    opcion = leer();
}

void subMenu(string opcion)
{
    system("cls");
    cout << "1." << opcion << " Maestros" << endl;
    cout << "2." << opcion << " Esudiantes" << endl;
    cout << "3.Volver" << endl;
    cout << "Ingrese una opcion del menu: ";
    subOpcion = leer();
}

void switchesAgregar(string opcion)
{
    do
    {
        subMenu(opcion);

        switch (subOpcion)
        {
        case 1:
            addMaestro();
            break;
        case 2:
            addEstudiante();
            break;

        default:
            break;
        }
    } while (subOpcion != 3);
}

void switchesImprimir(string opcion)
{
    do
    {
        subMenu(opcion);

        switch (subOpcion)
        {
        case 1:
            ordenarMaestros();
            imprimirMaestro();
            break;
        case 2:
            ordenarEstudiantes();
            imprimirEstudiante();
            break;

        default:
            break;
        }
    } while (subOpcion != 3);
}

void addMaestro()
{
    system("cls");
    cin.ignore();
    cout << "AGREGAR MAESTROS" << endl;
    do
    {
        cout << "Nombre: ";
        getline(cin, maestro[indiceMaestro].info.nombre);
    } while (maestro[indiceMaestro].info.nombre == "");
    cout << "Edad: ";
    maestro[indiceMaestro].info.edad = leer();

    cin.ignore();
    do
    {
        cout << "Materia que imparte: ";
        getline(cin, maestro[indiceMaestro].materia);
    } while (maestro[indiceMaestro].materia == "");

    cout << "Salario: ";
    maestro[indiceMaestro].salario = validarSalario();

    indiceMaestro++;
    system("pause");
}

void addEstudiante()
{
    float promedio = 0;
    system("cls");
    cin.ignore();
    cout << "AGREGAR ESTUDIANTE" << endl;
    do
    {
        cout << "Nombre: ";
        getline(cin, estudiante[indiceEstudiante].info.nombre);
    } while (estudiante[indiceEstudiante].info.nombre == "");
    cout << "Edad: ";
    estudiante[indiceEstudiante].info.edad = leer();

    cout << "Ingresar notas" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Nota " << i + 1 << ": ";
        estudiante[indiceEstudiante].notas[i] = validarNota();
    }

    //? Calcular el promedio
    for (int i = 0; i < 4; i++)
    {
        promedio += estudiante[indiceEstudiante].notas[i];
    }

    promedio /= 4;

    estudiante[indiceEstudiante].promedio = promedio;

    indiceEstudiante++;
    system("pause");
}

void ordenarMaestros()
{
    Maestros aux;
    int minimo;

    for (int i = 0; i < indiceMaestro - 1; i++)
    {
        minimo = i;

        for (int j = i + 1; j < indiceMaestro; j++)
        {
            if (maestro[j].info.nombre < maestro[minimo].info.nombre)
            {
                minimo = j;
            }
        }

        if (minimo != i)
        {
            aux = maestro[i];
            maestro[i] = maestro[minimo];
            maestro[minimo] = aux;
        }
    }
}

void imprimirMaestro()
{
    system("cls");
    if (indiceMaestro == 0)
    {
        cout << "No hay maestros registrados";
    }
    else
    {
        gotoxy(15, 0);
        cout << "Lista de Maestros";
        gotoxy(0, 1);
        cout << "Nombre";
        gotoxy(20, 1);
        cout << "Edad";
        gotoxy(30, 1);
        cout << "Materia";
        gotoxy(50, 1);
        cout << "Salario";

        for (int i = 0; i < indiceMaestro; i++)
        {
            gotoxy(0, i + 2);
            cout << maestro[i].info.nombre;
            gotoxy(20, i + 2);
            cout << maestro[i].info.edad;
            gotoxy(30, i + 2);
            cout << maestro[i].materia;
            gotoxy(50, i + 2);
            cout << maestro[i].salario;
        }
    }

    cout << endl;
    system("pause");
}

void ordenarEstudiantes()
{
    Estudiantes aux;
    int minimo;

    for (int i = 0; i < indiceEstudiante - 1; i++)
    {
        minimo = i;

        for (int j = i + 1; j < indiceEstudiante; j++)
        {
            if (estudiante[j].info.nombre < estudiante[minimo].info.nombre)
            {
                minimo = j;
            }
        }

        if (minimo != i)
        {
            aux = estudiante[i];
            estudiante[i] = estudiante[minimo];
            estudiante[minimo] = aux;
        }
    }
}

void imprimirEstudiante()
{
    system("cls");
    if (indiceEstudiante == 0)
    {
        cout << "No hay estudiantes registrados";
    }
    else
    {
        gotoxy(15, 0);
        cout << "Lista de Estudiantes";
        gotoxy(0, 1);
        cout << "Nombre";
        gotoxy(20, 1);
        cout << "Edad";
        gotoxy(30, 1);
        cout << "Promedio";

        for (int i = 0; i < indiceEstudiante; i++)
        {
            gotoxy(0, i + 2);
            cout << estudiante[i].info.nombre;
            gotoxy(20, i + 2);
            cout << estudiante[i].info.edad;
            gotoxy(30, i + 2);
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

float validarSalario()
{
    float numero;

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
