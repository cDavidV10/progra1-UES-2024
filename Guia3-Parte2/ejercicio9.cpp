// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <limits>

#define filas 3
#define columnas 3

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

void guardar(int[filas][columnas]);
int leer();
void imprimir(int[filas][columnas]);

int main(int argc, char const *argv[])
{
    int matriz[filas][columnas];
    float promedioDiagonal = 0;

    guardar(matriz);

    cout << "Su matriz es" << endl;
    imprimir(matriz);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if ((i + j) + 1 == columnas)
            {
                promedioDiagonal += matriz[i][j];
            }
        }
    }

    promedioDiagonal /= filas;

    cout << "El promedio de la diagonal menor es de: " << promedioDiagonal;
    return 0;
}

void guardar(int matriz[filas][columnas])
{
    cout << "Rellenar matriz " << filas << "x" << columnas << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << "Ingresar nunero [" << i << "]" << "[" << j << "]: ";
            matriz[i][j] = leer();
        }
    }
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
            cout << "Dato Incorrecto, ingrese el dato nuevamente: ";
        }
        else
        {
            break;
        }
    }
    return numero;
}

void imprimir(int matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << matriz[i][j] << "\t";
        }

        cout << endl;
    }
}
