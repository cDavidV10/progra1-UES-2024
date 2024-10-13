// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

#define size 5

void guardar(int[]);
int menu();
int leer();
int sumaElementos(int[]);
void minMax(int[], int &, int &);
void productoEscalar(int[], int[]);

int main(int argc, char const *argv[])
{
    int vector[size], minimo, maximo, resultado[size], opcion, suma;

    cout << "Ingrese 5 numeros" << endl;

    guardar(vector);

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            suma = sumaElementos(vector);
            cout << "La suma de los elementos es: " << suma << endl;

            break;
        case 2:
            minMax(vector, minimo, maximo);

            cout << "El valor minimo es: " << minimo << endl;
            cout << "El valor maximo es: " << maximo << endl;
            break;
        case 3:
            productoEscalar(vector, resultado);

            cout << "El producto escalar de su vector es: " << endl;

            for (int i = 0; i < size; i++)
            {
                cout << resultado[i] << endl;
            }

        default:
            cout << "La opcion ingresada no esta dentro de nuestro sistema" << endl;
            break;
        }
    } while (opcion != 4);

    cout << "Gracias por usar nuestro sistema :)";

    return 0;
}

void guardar(int vector[])
{

    for (int i = 0; i < size; i++)
    {
        cout << "Ingrese su numero " << i + 1 << ": ";
        vector[i] = leer();
    }
}

int menu()
{
    int opcion;
    cout << "QUE DESEA HACER" << endl;
    cout << "1. Sumar elementos" << endl;
    cout << "2. Encontrar el valor minimo y maximo" << endl;
    cout << "3. Realice el producto escalar del vector" << endl;
    cout << "4. Salir" << endl;
    cout << "Digite su opcion: ";

    opcion = leer();

    return opcion;
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

int sumaElementos(int vector[])
{
    int suma = 0;
    for (int i = 0; i < size; i++)
    {
        suma += vector[i];
    }

    return suma;
}

void minMax(int vector[], int &minimo, int &maximo)
{
    maximo = vector[0];
    minimo = vector[0];

    for (int i = 1; i < size; i++)
    {
        if (vector[i] > maximo)
        {
            maximo = vector[i];
        }
        else
        {
            minimo = vector[i];
        }
    }
}

void productoEscalar(int vector[], int resultado[])
{
    int escalar;

    cout << "Ingrese su valor escalar: ";
    escalar = leer();
    for (int i = 0; i < size; i++)
    {
        resultado[i] = vector[i] * escalar;
    }
}