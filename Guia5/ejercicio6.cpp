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
int opcion = 0, indice = 0, posicion = 0;

struct Libros
{
    string titulo;
    string autor;
    int anio;
    string genero;
    string estado;
} libro[size];

void menu();
void add();
void ordenar();
void imprimir();
void buscar();
bool busqueda(string);
void mayus();
int leer();
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
            ordenar();
            imprimir();
            break;
        case 3:
            ordenar();
            buscar();
            break;

        default:
            break;
        }
    } while (opcion != 4);

    cout << "Gracias por usar nuestro sistema :)";

    return 0;
}

void menu()
{
    system("cls");
    cout << "1. Agregar libro" << endl;
    cout << "2. Mostrar libros" << endl;
    cout << "3. Buscar libro" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese una opcion: ";
    opcion = leer();
}

void add()
{
    system("cls");
    cin.ignore();
    cout << "REGISTRO DE LIBRO" << endl;
    do
    {
        cout << "Titulo: ";
        getline(cin, libro[indice].titulo);
    } while (libro[indice].titulo == "");

    do
    {
        cout << "Autor: ";
        getline(cin, libro[indice].autor);
    } while (libro[indice].autor == "");

    cout << "Anio de publicacion: ";
    libro[indice].anio = leer();

    cin.ignore();
    do
    {
        cout << "Genero: ";
        getline(cin, libro[indice].genero);
    } while (libro[indice].genero == "");

    do
    {
        cout << "Estado: ";
        getline(cin, libro[indice].estado);
    } while (libro[indice].estado == "");

    indice++;
    system("pause");
}

void ordenar()
{
    Libros aux;
    int pos;

    for (int i = 0; i < indice; i++)
    {
        mayus();
        aux = libro[i];
        pos = i;

        while (pos > 0 && aux.titulo < libro[pos - 1].titulo)
        {
            libro[pos] = libro[pos - 1];
            pos--;
        }

        libro[pos] = aux;
    }
}

void imprimir()
{
    system("cls");
    if (indice == 0)
    {
        cout << "No hay libros registrados";
    }
    else
    {
        system("cls");
        gotoxy(50, 0);
        cout << "Lista de libros";
        gotoxy(0, 1);
        cout << "Autor";
        gotoxy(30, 1);
        cout << "Titulo";
        gotoxy(60, 1);
        cout << "Genero";
        gotoxy(80, 1);
        cout << "Anio";
        gotoxy(90, 1);
        cout << "Estado";

        for (int i = 0; i < indice; i++)
        {
            gotoxy(0, i + 2);
            cout << libro[i].autor;
            gotoxy(30, i + 2);
            cout << libro[i].titulo;
            gotoxy(60, i + 2);
            cout << libro[i].genero;
            gotoxy(80, i + 2);
            cout << libro[i].anio;
            gotoxy(90, i + 2);
            cout << libro[i].estado;
        }
    }
    cout << endl;
    system("pause");
}

void buscar()
{
    system("cls");
    string aux;
    cin.ignore();
    do
    {
        cout << "Titulo a buscar: ";
        getline(cin, aux);
    } while (aux == "");

    for (int i = 0; i < aux.size(); i++)
    {
        aux[i] = toupper(aux[i]);
    }

    if (busqueda(aux))
    {
        cout << "Titulo encontrado" << endl;
        gotoxy(0, 2);
        cout << libro[posicion].autor;
        gotoxy(30, 2);
        cout << libro[posicion].titulo;
        gotoxy(60, 2);
        cout << libro[posicion].genero;
        gotoxy(80, 2);
        cout << libro[posicion].anio;
        gotoxy(90, 2);
        cout << libro[posicion].estado;
    }
    else
    {
        cout << "Titulo no encontrado";
    }
    cout << endl;
    system("pause");
}

bool busqueda(string aux)
{
    bool bandera = false;
    int i = 0;

    while ((bandera == false) && (i < indice))
    {
        if (libro[i].titulo == aux)
        {
            bandera = true;
            posicion = i;
        }
        i++;
    }

    return bandera;
}

void mayus()
{
    for (int i = 0; i < indice; i++)
    {
        for (int j = 0; j < libro[i].titulo.size(); j++)
        {
            libro[i].titulo[j] = toupper(libro[i].titulo[j]);
        }
    }
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
