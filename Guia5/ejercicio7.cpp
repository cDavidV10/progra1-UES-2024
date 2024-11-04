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
using std::to_string;

const int size = 200;
int opcion = 0, totalClasificacion = 0;
int subOpcion = 0, totalPaciente = 0;
struct Pacientes
{
    string nombre;
    int edad;
    float peso;
    string codigo;
} paciente[size];

struct Clasificacion
{
    string nombre;
    int correlativo;
} clasificaciones[size];

void menu();
void subMenu();
void add();
void imprimir(string);
string generarCodigo(string);
string mayus(string);
void mostrar();
int leer();
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
            subMenu();
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
    cout << "BIENVENIDOS" << endl;
    cout << "1. agregar paciente" << endl;
    cout << "2. Mostrar pacientes" << endl;
    cout << "3. salir" << endl;
    cout << "Seleccione una opcion: ";
    opcion = leer();
}

void subMenu()
{
    string seleccion;
    system("cls");

    if (totalClasificacion == 0)
    {
        cout << "No hay registros" << endl;
        system("pause");
        return;
    }

    do
    {
        system("cls");
        mostrar();
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        subOpcion = leer();

        if (subOpcion == 0)
        {
            break;
        }
        else if (subOpcion > 0 && subOpcion <= totalClasificacion)
        {
            seleccion = clasificaciones[subOpcion - 1].nombre;
            imprimir(seleccion);
        }
        else
        {
            cout << "Opción inválida. Intente de nuevo." << endl;
            system("pause");
        }

    } while (true);

    cout << endl;
}

void add()
{
    cin.ignore();
    string clasificaion;
    system("cls");
    cout << "REGISTRO DE PACIENTE" << endl;
    do
    {
        cout << "Nombre: ";
        getline(cin, paciente[totalPaciente].nombre);
    } while (paciente[totalPaciente].nombre == "");

    cout << "Edad: ";
    paciente[totalPaciente].edad = leer();

    cout << "Peso: ";
    cin >> paciente[totalPaciente].peso;

    cin.ignore();
    do
    {
        cout << "Clasificacion: ";
        getline(cin, clasificaion);
    } while (clasificaion == "");

    paciente[totalPaciente].codigo = generarCodigo(clasificaion);

    totalPaciente++;
    system("pause");
}

void imprimir(string clasificacion)
{
    system("cls");
    gotoxy(15, 0);
    cout << "Lista de " << clasificacion;
    gotoxy(0, 1);
    cout << "Codigo";
    gotoxy(20, 1);
    cout << "Nombre";
    gotoxy(35, 1);
    cout << "Peso";
    gotoxy(50, 1);
    cout << "Edad";

    clasificacion = mayus(clasificacion);
    int lineNumber = 2;

    for (int i = 0; i < totalPaciente; i++)
    {
        if (mayus(paciente[i].codigo.substr(0, 2)) == clasificacion.substr(0, 2))
        {
            gotoxy(0, lineNumber);
            cout << paciente[i].codigo;
            gotoxy(20, lineNumber);
            cout << paciente[i].nombre;
            gotoxy(35, lineNumber);
            cout << paciente[i].peso;
            gotoxy(50, lineNumber);
            cout << paciente[i].edad;

            lineNumber++;
        }
    }

    cout << endl;
    system("pause");
}

string generarCodigo(string clasificacion)
{
    string codigo;
    clasificacion = mayus(clasificacion);

    for (int i = 0; i < totalClasificacion; i++)
    {
        if (clasificaciones[i].nombre == clasificacion)
        {
            codigo = clasificacion.substr(0, 2);
            codigo += string(4 - to_string(clasificaciones[i].correlativo).length(), '0') + to_string(clasificaciones[i].correlativo);

            clasificaciones[i].correlativo++;

            return codigo;
        }
    }

    if (totalClasificacion < size)
    {
        clasificaciones[totalClasificacion].nombre = clasificacion;
        clasificaciones[totalClasificacion].correlativo = 2;
        codigo = clasificacion.substr(0, 2);
        codigo += "0001";

        totalClasificacion++;
    }

    return codigo;
}

void mostrar()
{
    cout << "Clasificaciones registradas" << endl;
    for (int i = 0; i < totalClasificacion; ++i)
    {
        cout << i + 1 << ". " << clasificaciones[i].nombre << endl;
    }
}

string mayus(string cadena)
{
    for (int i = 0; i < cadena.size(); i++)
    {
        cadena[i] = toupper(cadena[i]);
    }
    return cadena;
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

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hcon, coord);
}
