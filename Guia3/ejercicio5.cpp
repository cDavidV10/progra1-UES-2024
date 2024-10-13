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
void sumaMatriz(int[filas][columnas]);
void multiplicacionMatriz(int[filas][columnas]);
void imprimir(int[filas][columnas]);

int main(int argc, char const *argv[])
{
    int matriz[filas][columnas];

    guardar(matriz);

    cout << "Su matriz es: " << endl;
    imprimir(matriz);

    sumaMatriz(matriz);

    multiplicacionMatriz(matriz);

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

        if (cin.fail())
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

void sumaMatriz(int matriz[filas][columnas])
{
    int suma;
    for (int i = 0; i < filas; i++)
    {
        suma = 0;
        for (int j = 0; j < columnas; j++)
        {
            suma += matriz[i][j];
        }
        cout << "La suma de la fila " << i + 1 << " es de: " << suma << endl;
    }
}

void multiplicacionMatriz(int matriz[filas][columnas])
{
    int multiplicacion;
    for (int i = 0; i < filas; i++)
    {
        multiplicacion = 1;
        for (int j = 0; j < columnas; j++)
        {
            multiplicacion *= matriz[j][i];
        }
        cout << "La multiplicacion de la columna " << i + 1 << " es de: " << multiplicacion << endl;
    }
}
