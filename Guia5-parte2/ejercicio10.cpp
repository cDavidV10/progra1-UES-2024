#include <iostream>
#include <cstring>

using namespace std;

struct Direccion_Postal
{
    union
    {
        int numCasa;
        int numApartamento;
    };
    char calle[100];
    bool isCasa;
};

int main()
{
    Direccion_Postal direccion;
    char respuesta;

    cout << "-----    Registro de Direccion Postal    -----" << endl;

    cout << "Ingrese el nombre de la calle: ";
    cin.getline(direccion.calle, 100);
    cout << "Es una casa? (s/n): ";
    cin >> respuesta;

    direccion.isCasa = (respuesta == 's' || respuesta == 'S');

    if (direccion.isCasa)
    {
        cout << "Ingrese el numero de la casa: ";
        cin >> direccion.numCasa;
    }
    else
    {
        cout << "Ingrese el numero de apartamento: ";
        cin >> direccion.numApartamento;
    }

    cout << "\nDireccion Postal Completa:" << endl;
    if (direccion.isCasa)
    {
        cout << "Casa: No" << direccion.numCasa << ", Calle. " << direccion.calle << endl;
    }
    else
    {
        cout << "Apartamento: No" << direccion.numApartamento << ", calle. " << direccion.calle << endl;
    }

    return 0;
}
