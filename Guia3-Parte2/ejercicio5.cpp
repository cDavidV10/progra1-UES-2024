// Carlos David Vasquez Rivas   VR24001

#include <iostream>

#define filas 3
#define columnas 3

using std::cin;
using std::cout;
using std::endl;

void ingresar(int[filas][columnas]);
void impresion(int[filas][columnas]);
bool isRala(int[filas][columnas]);

int main()
{
    int matriz[filas][columnas];

    cout << "Programa para determinar si la matriz 3x3 es rala" << endl;
    cout << "Ingrese elementos de la matriz [0 o 1]: " << endl;

    ingresar(matriz);

    impresion(matriz);

    if (isRala(matriz))
    {
        cout << "La matriz es rala" << endl;
    }
    else
    {
        cout << "La mattriz no es rala" << endl;
    }

    return 0;
}

void ingresar(int matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            do
            {
                cout << "Ingrese elmento [" << i << "][" << j << "]: ";
                cin >> matriz[i][j];

                if (matriz[i][j] != 0 && matriz[i][j] != 1)
                {
                    cout << "Solo se permite 0 o 1" << endl;
                }

            } while (matriz[i][j] != 0 && matriz[i][j] != 1);
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

bool isRala(int matriz[filas][columnas])
{
    bool isEncontrado;

    // Para buscar en las filas
    for (int i = 0; i < filas; i++)
    {
        isEncontrado = false;
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j] == 1)
            {
                if (isEncontrado)
                {
                    return false;
                }

                isEncontrado = true;
            }
        }
    }
    // Para buscar en las columnas
    for (int i = 0; i < filas; i++)
    {
        isEncontrado = false;
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[j][i] == 1)
            {
                if (isEncontrado)
                {
                    return false;
                }
                isEncontrado = true;
            }
        }
    }

    return true;
}