// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    char *cadena[100];
    char caracter;
    int opcion, cambio;

    cout << "\t\tPrograma para sustituir caracteres" << endl;
    cout << "Introduzca su texto: ";
    cin.getline(*cadena, 100);

    cout << "\t\t MENU" << endl;
    cout << "1.Remplazar toda la cadena" << endl;
    cout << "2.Remplazar caracteres indicados" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        cout << "Ingrese el caracter por el que desea cambiar el texto: ";
        cin >> caracter;

        cout << strset(*cadena, caracter);
        break;
    case 2:
        cout << "Ingrese el caracter por el que desea cambiar el texto: ";
        cin >> caracter;
        cout << "Ingrese la cantidad de caracteres a cambiar: ";
        cin >> cambio;

        cout << strnset(*cadena, caracter, cambio);
        break;

    default:
        cout << "La opcion ingresada no es valida" << endl;
        break;
    }
    return 0;
}
