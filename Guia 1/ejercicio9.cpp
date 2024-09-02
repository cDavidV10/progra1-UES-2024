// Carlos David Vásquez Rivas VR24001

#include <iostream>
#include <cmath>

#define pi 3.141592654
#define n 17

using std::cin;
using std::cout;
using std::endl;

void leer(float &);
unsigned long long FACTORIAL(int);
void taylor(double &, float);

int main(int argc, char const *argv[])
{
    float angulo;
    double resultado = 0.0;

    cout << "\t\t\t\t CALCULO DEL SENO MEDIANTE LA SERIE DE TAYLOR" << endl;

    leer(angulo);

    taylor(resultado, angulo);

    cout << "El seno del angulo ingresado es de: " << resultado;

    return 0;
}

void leer(float &angulo)
{
    do
    {
        cout << "Ingrese el valor del angulo en grados: ";
        cin >> angulo;
    } while (angulo < 0 || angulo > 360);

    angulo = (angulo * pi) / 180;
}

unsigned long long FACTORIAL(int numero)
{
    unsigned long long factorial = 1;
    for (int i = 1; i <= numero; i++)
    {
        factorial *= i;
    }

    return factorial;
}

void taylor(double &resultado, float angulo)
{
    resultado = 0.0;
    for (int i = 0; i <= n; i++)
    {

        resultado += pow(-1, i) * (pow(angulo, ((2 * i) + 1)) / (FACTORIAL((2 * i) + 1)));
    }
}
