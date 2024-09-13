// Carlos David Vásquez Rivas   VR24001
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string mayus(string);
int conversion(string);
int valores(char cadena);

int main(int argc, char const *argv[])
{
    string romano;
    int total;

    cout << "Numero Romano: ";
    getline(cin, romano);

    romano = mayus(romano);

    total = conversion(romano);

    cout << "Su numero en decimal es: " << total;

    return 0;
}

string mayus(string cadena)
{
    for (int i = 0; i < cadena.length(); i++)
    {
        cadena[i] = toupper(cadena[i]);
    }

    return cadena;
}

int conversion(string cadena)
{
    int actual = 0, anterior = 0, total = 0;

    for (int i = cadena.length() - 1; i >= 0; i--)
    {
        actual = valores(cadena[i]);

        if (actual < anterior)
        {
            total -= actual;
        }
        else
        {
            total += actual;
        }

        anterior = actual;
    }

    return total;
}

int valores(char cadena)
{
    switch (cadena)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;

    default:
        break;
    }
    return 0;
}