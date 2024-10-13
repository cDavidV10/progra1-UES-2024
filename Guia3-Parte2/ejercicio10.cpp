// Carlos David Vásquez Rivas   VR24001

#include <iostream>

#define filas 5
#define columnas 5

using std::cin;
using std::cout;
using std::endl;

void rellenado(int[filas][columnas]);
void impresion(int[filas][columnas]);
void cambio(int[filas][columnas]);

int main(int argc, char const *argv[])
{
    int matriz[filas][columnas];

    rellenado(matriz);
    impresion(matriz);
    cambio(matriz);

    return 0;
}

void rellenado(int matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

void impresion(int matriz[filas][columnas])
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

void cambio(int matriz[filas][columnas])
{
    int numero;

    cout << "Ingrese el numero para cambiar: ";
    cin >> numero;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i == j)
            {
                matriz[i][j] = numero;
            }
        }
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if ((j + i) + 1 == columnas)
            {
                matriz[i][j] = numero;
            }
        }
    }

    impresion(matriz);
}
