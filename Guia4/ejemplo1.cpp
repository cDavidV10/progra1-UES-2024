#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int MAX = 10;
int N = 3;
int edad[MAX];
string nombre[MAX], direccion[MAX], responsable[MAX];

int main(int argc, char const *argv[])
{
    nombre[0] = "Genesis Nicoll Escobar Canias";
    edad[0] = 18;
    direccion[0] = "Escalon, San Salvador";

    nombre[1] = "Milena de los Angeles";
    nombre[1] = 33;
    direccion[1] = "Tecoluca";

    nombre[2] = "Ricardo Ricardito Villabaja";
    edad[2] = 10;
    direccion[2] = "Apastepeque";
    responsable[2] = "Tito Bukele";

    return 0;
}

void menu()
{
    int op;

    system("cls");
    cout << "Bienvenido al programa" << endl;
    cout << "1. Registrar" << endl;
    cout << "2. Modificar" << endl;
    cout << "3. Lista de cliente" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione: ";
    cin >> op;

    switch (op)
    {
    case 1:
        registrar();
        break;
    case 2:
        modificar();
        break;
    case 3:
        ver();
        break;
    case 4:
        exit(0);
        break;

    default:
        break;
    }
}

void lista()
{
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ". " << nombre[i] << endl;
    }
}

void registrar()
{
    system("cls");
    cin.ignore();

    cout << "Registro de Cliente" << endl;
    cout << "Cliente " << N + 1 << endl;
    cout << "Nombre: ";
    getline(cin, nombre[N]);

    cout << "Edad: ";
    cin >> edad[N];
    cin.ignore();

    if (edad[N] < 18)
    {
        cout << "Responsable: ";
        getline(cin, responsable[N]);
    }

    cout << "Direccion: ";
    getline(cin, nombre[N]);

    N++;

    cout << "Registro completado, presione cuaalquier tecla para continuar";
    system("pause>null");
    menu();
}

void modificar()
{
    system("cls");

    int op, opMod;
    string auxNombre, auxDireccion, auxResponsable;
    int auxEdad;

    ordenar();
    cout << "Lista de Clientes" << endl;
    lista();

    cout << "Seleccione un cliente para modificar: ";
    cin >> op;
    op--;
    system("cls");
    cout << "Editando Cliente" << endl;
    cout << "Que desea modificar?" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Edad" << endl;
    cout << "3, Direccion" << endl;

    if (edad[op] < 18)
    {
        cout << "4. Responsable: ";
    }

    cout << "Seleccione: ";
    cin >> opMod;
    cin.ignore();

    switch (opMod)
    {
    case 1:
        cout << "Nombre Actual: " << nombre[op] << endl;
        cout << "Nuevo nombre: ";
        getline(cin, auxNombre);

        nombre[op] = auxNombre;
        break;
    case 2:
        cout << "Edad Actual: " << edad[op] << endl;
        cout << "Nueva edad: ";
        cin >> auxEdad;

        edad[op] = auxEdad;
        break;
    case 3:
        cout << "Direccion Actual: " << direccion[op] << endl;
        cout << "Nueva direccion: ";
        getline(cin, auxDireccion);

        direccion[op] = auxDireccion;
        break;
    case 4:
        cout << "Responsable Actual: " << responsable[op] << endl;
        cout << "Nuevo responsable: ";
        getline(cin, auxResponsable);

        responsable[op] = auxResponsable;
        break;

    default:
        break;
    }

    menu();
}

void ver()
{
    system("cls");
    int op;

    lista();

    cout << "Seleccione un cliente para ver los datos: ";
    cin >> op;
    op--;

    cout << "Nombre: " << nombre[op] << endl;
    cout << "Edad: " << edad[op] << endl;
    cout << "Direccion: " << direccion[op] << endl;

    if (edad[op] < 18)
    {
        cout << "Responsable: " << responsable[op] << endl;
    }

    cout << "Presione cualquier tecla para continuar";
    system("pause<null");
    menu();
}

void ordenar()
{
    string auxNombre, auxDireccion, auxResponsable;
    int auxEdad;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - (i - 1); j++)
        {
            if (nombre[j] > nombre[j + 1])
            {
                auxNombre = nombre[j];
                nombre[j] = nombre[j + 1];
                nombre[j + 1] = auxNombre;

                auxDireccion = direccion[j];
                direccion[j] = direccion[j + 1];
                direccion[j + 1] = auxDireccion;

                auxResponsable = responsable[j];
                responsable[j] = responsable[j + 1];
                responsable[j + 1] = auxResponsable;

                auxEdad = edad[j];
                edad[j] = edad[j + 1];
                direccion[j + 1] = auxEdad;
            }
        }
    }
}