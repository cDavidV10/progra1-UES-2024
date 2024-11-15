#include <iostream>
#include <string>

using namespace std;

union Moneda
{
    float dolares;
    float pesos;
    float euros;
} moneda;

void pesos();
void euros();

int main()
{
    int opcion;

    cout << "Ingrese el valor en dolares: $";
    cin >> moneda.dolares;

    cout << "\nSeleccione la moneda que desea mostrar" << endl;
    cout << "1. Pesos" << endl;
    cout << "2. Euros" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    cout << "Valor en la moneda seleccionada: ";
    switch (opcion)
    {
    case 1:
        pesos();
        cout << moneda.pesos << " MXN" << endl;
        break;
    case 2:
        euros();
        cout << moneda.euros << " EUR" << endl;
        break;
    default:
        cout << "Opción no válida." << endl;
        break;
    }

    return 0;
}

void pesos()
{
    moneda.pesos = moneda.dolares * 20.37;
}

void euros()
{
    moneda.euros = moneda.dolares * 0.95;
}
