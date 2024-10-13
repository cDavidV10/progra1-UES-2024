// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <limits>

#define filas 2
#define columnas 2

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

void guardar(int[filas][columnas]);
void imprimir(int[filas][columnas]);
void multiplicacionMatriz(int[filas][columnas], int[filas][columnas], int[filas][columnas]);
void sumaMatriz(int[filas][columnas], int[filas][columnas], int[filas][columnas]);
int leer();

int main(int argc, char const *argv[])
{
    int matrizA[filas][columnas], matrizB[filas][columnas], suma[filas][columnas], multiplicacion[filas][columnas];

    cout << "Matriz A" << endl;
    guardar(matrizA);

    cout << "Matriz B" << endl;
    guardar(matrizB);

    cout << "La matriz A es:" << endl;
    imprimir(matrizA);

    cout << "La matriz B es:" << endl;
    imprimir(matrizB);

    sumaMatriz(matrizA, matrizB, suma);
    multiplicacionMatriz(matrizA, matrizB, multiplicacion);

    cout << "La suma de la matrizA y MatrizB es de: " << endl;
    imprimir(suma);

    cout << "La multiplicacion de la matrizA x MatrizB es de: " << endl;
    imprimir(multiplicacion);

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

void multiplicacionMatriz(int matrizA[filas][columnas], int matrizB[filas][columnas], int multiplicacion[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            multiplicacion[i][j] = matrizA[i][j] * matrizB[i][j];
        }
    }
}

void sumaMatriz(int matrizA[filas][columnas], int matrizB[filas][columnas], int multiplicacion[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            multiplicacion[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}
