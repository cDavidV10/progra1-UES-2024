// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

#define size 5

void guardar(float[]);
float leer();
float pagoTotal(float[]);

int main(int argc, char const *argv[])
{
    float consumos[size], pago = 0;

    cout << "Digite el precio de 5 consumos" << endl;

    guardar(consumos);

    pago = pagoTotal(consumos);

    cout << "El total a pagar es: $" << pago;

    return 0;
}

void guardar(float vector[])
{

    for (int i = 0; i < size; i++)
    {
        cout << "Ingrese su consumo " << i + 1 << ": $";
        vector[i] = leer();
    }
}

float leer()
{
    float numero;

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

float pagoTotal(float vector[])
{
    float pago;

    for (int i = 0; i < size; i++)
    {
        if (vector[i] >= 2.50)
        {
            cout << "Se le aplico un 7% de descuento" << endl;
            cout << "Precio anterior: &" << vector[i] << endl;
            cout << "Nuevo precio: &" << vector[i] - (vector[i] * 0.07) << endl;
            pago += vector[i] - (vector[i] * 0.07);
        }
        else
        {
            pago += vector[i];
        }
    }

    return pago;
}
