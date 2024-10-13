// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <limits>

#define filas 200
#define columnas 6

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;

void guardar(int[filas][columnas], string[6]);
float leer();
void imprimir(int[filas][columnas], string[6]);
void mayorVenta(int[filas][columnas], string[6]);

int cantidad = 0;

int main(int argc, char const *argv[])
{
    int matriz[filas][columnas];
    string dias[6] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

    guardar(matriz, dias);

    cout << "Detalles de venta" << endl;
    imprimir(matriz, dias);

    mayorVenta(matriz, dias);

    return 0;
}

void guardar(int matriz[filas][columnas], string dias[])
{

    char respuesta;
    int indice = 0;

    for (int i = 0; i < columnas; i++)
    {
        system("cls");
        indice = 0;
        cout << "Ventas del dia " << dias[i] << endl;
        do
        {
            cout << "Ventas del producto " << indice + 1 << ": $";
            matriz[indice][i] = leer();

            indice++;

            cout << "Desea agregar otro producto para el dia? (s/n): ";
            cin >> respuesta;
        } while (respuesta == 's' || respuesta == 'S');

        /*
        TODO: Esta forma sirve unicamente cuando el dia siguiente tiene mas que el anterior, es decir que si el dia
        Todo: 1 tiene mas que el 2 se rompe el programa :( o si el dia 2 tiene mas que el 1 y el 3 tambien
        todo: se rompe el programa :(
        */
        if (indice > cantidad)
        {
            for (int k = 0; k < i; k++)
            {
                for (int j = cantidad; j < indice; j++)
                {
                    matriz[j][k] = 0;
                }
            }
        }

        cantidad = (indice > cantidad) ? indice : cantidad;
    }
    system("cls");
}

float leer()
{
    float numero;

    while (true)
    {
        cin >> numero;

        if (cin.fail() || numero < 0)
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

void imprimir(int matriz[filas][columnas], string dias[])
{
    for (int i = 0; i < columnas; i++)
    {
        cout << dias[i] << "";
    }
    cout << endl;

    for (int i = 0; i < cantidad; i++)
    {

        for (int j = 0; j < columnas; j++)
        {
            cout << matriz[i][j] << "\t";
        }

        cout << endl;
    }
}

void mayorVenta(int matriz[filas][columnas], string dias[])
{
    int ventas[columnas] = {0};
    int venta = 0, index;
    string dia;

    for (int i = 0; i < columnas; i++)
    {
        for (int j = 0; j < cantidad; j++)
        {
            ventas[i] += matriz[j][i];
        }

        if (ventas[i] > venta)
        {
            venta = ventas[i];
            dia = dias[i];
        }
    }

    cout << "El dia " << dia << " tiene mayor venta: " << venta;
}
