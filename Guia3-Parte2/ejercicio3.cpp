#include <iostream>
#include <limits>

#define filas 200
#define columnas 200

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

int leer();

int main(int argc, char const *argv[])
{
    int n, m;
    int matriz[filas][columnas];
    float promedio = 0, promedioFilas = 0, promedioColumnas = 0;

    cout << "Digite la cantidas de filas de su matriz: ";
    n = leer();

    cout << "Digite la cantidas de columnas de su matriz: ";
    m = leer();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << "Ingrese elmento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            promedio += matriz[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matriz[i][j] << "\t";
        }

        cout << endl;
    }

    promedio /= (n * m);

    if (n == m)
    {
        cout << "Su matriz es cuadrada" << endl;
    }
    else
    {

        cout << "Su matriz no es cuadrada" << endl;
    }

    cout << "El promedio de la matriz es de: " << promedio << endl;

    for (int i = 0; i < n; i++)
    {
        promedioFilas = 0.0;
        for (int j = 0; j < m; j++)
        {
            promedioFilas += matriz[i][j];
        }
        promedioFilas /= m;
        cout << "El promedio de la fila " << i + 1 << " es de: " << promedioFilas << endl;
    }

    for (int i = 0; i < m; i++)
    {
        promedioColumnas = 0.0;
        for (int j = 0; j < n; j++)
        {
            promedioColumnas += matriz[j][i];
        }
        promedioColumnas /= n;
        cout << "El promedio de la columna " << i + 1 << " es: " << promedioColumnas << endl;
    }

    return 0;
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
