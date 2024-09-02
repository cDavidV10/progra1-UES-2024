// Carlos David Vásquez Rivas VR24001

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int validar(int, int);

int main()
{
    int horas, minutos, segundos;
    cout << "Escriba la hora en formato de 24 horas" << endl;

    cout << "Escriba la hora: ";
    horas = validar(0, 24);

    cout << "Escriba la minutos: ";
    minutos = validar(0, 60);

    cout << "Escriba la segundos: ";
    segundos = validar(0, 60);

    segundos++;

    if (segundos == 60)
    {
        minutos++;
        segundos = 0;
    }

    if (minutos == 60)
    {
        horas++;
        minutos = 0;
    }

    if (horas == 24)
    {
        horas = 0;
    }

    cout << horas << ":" << minutos << ":" << segundos;
    return 0;
}

int validar(int minimo, int maximo)
{
    int hora;
    do
    {
        cin >> hora;
    } while (hora <= minimo || hora >= maximo);

    return hora;
}