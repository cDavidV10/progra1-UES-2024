// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int digitos(int);
int sumaImpar(char[]);
int sumaPar(char[]);

int main()
{
    char tarjeta[200], numTarjeta[200] = "";
    char *auxiliar;
    int resultado = 0;

    cout << "Digite su tarjeta: ";
    gets(tarjeta);

    auxiliar = strtok(tarjeta, " ");

    while (auxiliar != NULL)
    {
        strcat(numTarjeta, auxiliar);
        auxiliar = strtok(NULL, " ");
    }

    resultado = sumaPar(numTarjeta) + sumaImpar(numTarjeta);

    if (resultado % 10 == 0)
    {
        cout << "La tarjeta de credito es valida" << endl;
    }
    else
    {
        cout << "La tarjeta de credito no es valida" << endl;
    }

    return 0;
}

int digitos(int numero)
{
    return numero % 10 + (numero / 10 % 10);
}

int sumaImpar(char tarjeta[])
{
    int suma = 0;

    for (int i = strlen(tarjeta) - 1; i >= 0; i -= 2)
    {
        suma += tarjeta[i] - '0';
    }

    return suma;
}

int sumaPar(char tarjeta[])
{
    int suma = 0;

    for (int i = strlen(tarjeta) - 2; i >= 0; i -= 2)
    {
        suma += digitos((tarjeta[i] - '0') * 2);
    }

    return suma;
}
