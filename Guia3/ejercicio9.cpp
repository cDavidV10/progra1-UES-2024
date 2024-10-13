// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <limits>

#define filas 5
#define columnas 5

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

void rellenar(int[filas][columnas]);
int leer();
void imprimir(int[filas][columnas]);
void cambio(int[filas][columnas]);

int main(int argc, char const *argv[])
{
    int matrizA[filas][columnas];

    rellenar(matrizA);

    cout << "Su matriz es" << endl;
    imprimir(matrizA);

    cambio(matrizA);

    cout << "Su nueva matriz es" << endl;
    imprimir(matrizA);

    return 0;
}

void rellenar(int matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = 0;
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

void cambio(int matriz[filas][columnas])
{
    int numero;

    cout << "Digite el numero que desee que aparezca: ";
    cin >> numero;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i == 0 || j == 0)
            {
                matriz[i][j] = numero;
            }
            if (i + 1 == filas || j + 1 == columnas)
            {
                matriz[i][j] = numero;
            }
        }
    }
}
