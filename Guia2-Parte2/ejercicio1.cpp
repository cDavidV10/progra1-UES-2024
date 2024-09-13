// Crlos David Vásquez Rivas    VR24001
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    int minimo = 0, maximo = 0;
    string cadena, auxiliar;
    char delimitador;

    cout << "Simular strtok en strings" << endl;
    cout << "Ingrese la cadena: ";
    getline(cin, cadena);
    cout << "Ingrese delimitador: ";
    cin >> delimitador;

    for (int i = 0; i <= cadena.length(); i++)
    {
        if (cadena[i] == delimitador || cadena[i] == '\0')
        {
            maximo = i - minimo;
            if (i - minimo != 0)
            {
                auxiliar = cadena.substr(minimo, maximo);
                cout << auxiliar << endl;
            }
            minimo = i + 1;
        }
    }
    return 0;
}
