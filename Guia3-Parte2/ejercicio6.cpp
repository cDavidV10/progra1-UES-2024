// Carlos David Vásquez Rivas   VR24001

#include <iostream>

#define filas 3
#define columnas 3

using std::cin;
using std::cout;
using std::endl;

void guardar(int[filas][columnas]);
void imprimir(int[filas][columnas]);

int main(int argc, char const *argv[])
{
    int matriz[filas][columnas];

    guardar(matriz);

    cout << "Su matriz es" << endl;
    imprimir(matriz);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j] > 0)
            {
                matriz[i][j] = 9;
            }
            else
            {
                matriz[i][j] = 0;
            }
        }
    }

    cout << "Matriz modificada" << endl;
    imprimir(matriz);

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
            cin >> matriz[i][j];
        }
    }
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
