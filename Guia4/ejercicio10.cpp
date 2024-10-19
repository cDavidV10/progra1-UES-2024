// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>
#include <limits>
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;

const int size = 200;
const float iva = 0.13;
string productos[size];
int index = 0, opcion = 0;
int cantidades[size];
float precios[size];
bool ivaAgregado = false;

void menu();
int leer();
float leerPrecio();
void add();
void ordenar();
void imprimir(string[], int[], float[]);
void gotoxy(int x, int y);

int main(int argc, char const *argv[])
{
    do
    {
        menu();
        switch (opcion)
        {
        case 1:
            add();
            system("pause");
            break;
        case 2:
            ordenar();
            system("pause");
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
    cout << "*****  MENU    *****" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Ver factura" << endl;
    cout << "3. Salir" << endl;
    cout << "Selecione una opcion: ";
    opcion = leer();
}

void add()
{
    system("cls");
    cin.ignore();

    cout << "Agregar nuevo producto" << endl;
    cout << "Nombre: ";
    getline(cin, productos[index]);
    cout << "Cantidad a llevar: ";
    cantidades[index] = leer();

    cout << "Precio del producto: $";
    precios[index] = leerPrecio();
    index++;
}

void ordenar()
{
    string productoOrdenado[size];
    int cantidadOrdenada[size];
    float precioOrdenado[size];
    string productoAux;
    int cantidadAux;
    float precioAux;

    //? Calcular el precio final en base a la cantidad
    //? de productos llevados
    for (int i = 0; i < index; i++)
    {
        precios[i] = precios[i] * cantidades[i];
    }

    for (int i = 0; i < index; i++)
    {
        productoOrdenado[i] = productos[i];
        cantidadOrdenada[i] = cantidades[i];
        precioOrdenado[i] = precios[i];
    }

    //? For para agregarle el iva al precio
    if (!ivaAgregado)
    {
        for (int i = 0; i < index; i++)
        {
            precioOrdenado[i] += (precioOrdenado[i] * iva);
        }
        ivaAgregado = true;
    }

    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - (i + 1); j++)
        {
            if (precioOrdenado[j] > precioOrdenado[j + 1])
            {
                productoAux = productoOrdenado[j];
                productoOrdenado[j] = productoOrdenado[j + 1];
                productoOrdenado[j + 1] = productoAux;

                cantidadAux = cantidadOrdenada[j];
                cantidadOrdenada[j] = cantidadOrdenada[j + 1];
                cantidadOrdenada[j + 1] = cantidadAux;

                precioAux = precioOrdenado[j];
                precioOrdenado[j] = precioOrdenado[j + 1];
                precioOrdenado[j + 1] = precioAux;
            }
        }
    }

    imprimir(productoOrdenado, cantidadOrdenada, precioOrdenado);
}

int leer()
{
    int numero;

    while (true)
    {
        cin >> numero;
        if (cin.fail() || numero <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Dato Incorrecto, ingrese el dato nuevamente: ";
        }
        else
        {
            break;
        }
    }

    return numero;
}

float leerPrecio()
{
    float numero;

    while (true)
    {
        cin >> numero;
        if (cin.fail() || numero <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Dato Incorrecto, ingrese el dato nuevamente: ";
        }
        else
        {
            break;
        }
    }

    return numero;
}

void imprimir(string producto[], int cantidad[], float precio[])
{
    system("cls");
    cout.precision(3);
    if (index == 0)
    {
        cout << "No hay productos registrados" << endl;
    }
    else
    {
        gotoxy(10, 0);
        cout << "Lista de producto" << endl;
        gotoxy(0, 1);
        cout << "Cantidad";
        gotoxy(10, 1);
        cout << "Producto";
        gotoxy(30, 1);
        cout << "precio";

        for (int i = 0; i < index; i++)
        {
            gotoxy(0, i + 2);
            cout << cantidad[i];
            gotoxy(10, i + 2);
            cout << producto[i];
            gotoxy(30, i + 2);
            cout << "$" << precio[i];
        }
        cout << endl;
        cout << "Se le aplico un 13% de iva a todos sus productos" << endl;
    }
}

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
