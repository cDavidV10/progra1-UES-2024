// Carlos David Vásquez Rivas VR24001

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int captura();

int suma(int, int);
int resta(int, int);
int multiplicacion(int, int);
float division(int, int);
int modulo(int, int);

void mostrarResultado(int);

int main()
{
    int n1 = 0, n2 = 0, option;
    float resultado;

    cout << "Ingrese un numero:";
    n1 = captura();

    cout << "Ingrese otro numero:";
    n2 = captura();

    //	resultado = operacion (n1,n2);
    system("cls");

    cout << "*********MENU********" << endl;
    cout << "1- Suma" << endl;
    cout << "2- Resta" << endl;
    cout << "3- Multiplicacion" << endl;
    cout << "4- Division" << endl;
    cout << "5- Modulo" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        resultado = suma(n1, n2);
        cout << "La suma es: ";
        mostrarResultado(resultado);
        break;

    case 2:
        resultado = resta(n1, n2);
        cout << "La resta es: ";
        mostrarResultado(resultado);
        break;

    case 3:
        resultado = multiplicacion(n1, n2);
        cout << "La multiplicacion es: ";
        mostrarResultado(resultado);
        break;

    case 4:

        if (n2 == 0)
        {
            cout << "La division no se pude hacer" << endl;
        }
        else
        {
            resultado = division(n1, n2);
            cout << "La division es: ";
            mostrarResultado(resultado);
        }
        break;

    case 5:

        if (n2 == 0)
        {
            cout << "No se puede sacar el modulo" << endl;
        }
        else
        {
            resultado = modulo(n1, n2);
            cout << "La modulo es: ";
            mostrarResultado(resultado);
        }
        break;

    default:
        break;
    }

    return 0;
}

int captura() // funcion de p*valor
{
    int n = 0;
    cin >> n;
    return n;
}

int suma(int num1, int num2)
{
    return num1 + num2;
}

int resta(int num1, int num2)
{
    return num1 - num2;
}

int multiplicacion(int num1, int num2)
{
    return num1 * num2;
}

float division(int num1, int num2)
{
    return num1 / num2;
}

int modulo(int num1, int num2)
{
    return num1 % num2;
}

void mostrarResultado(int resultado)
{
    cout << resultado << endl;
}