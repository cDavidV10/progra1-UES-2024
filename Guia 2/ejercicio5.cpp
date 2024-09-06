// Carlos David Vásquez Rivas   VR24001

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string cadena, subcadena;
    int posicion;

    cout << "Ingrese su texto: ";
    getline(cin, cadena);

    cout << "Ingrese el texto a buscar: ";
    getline(cin, subcadena);

    posicion = cadena.find(subcadena);

    if (posicion == -1)
    {
        cout << "La palabra que quiere buscar no existe dentro de su texto";
    }
    else
    {
        cout << "La palabra deseada empieza en la posicion " << posicion << " de su texto";
    }
    return 0;
}
