// Carlos David Vásquez Rivas   VR24001
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    char cadena[200];
    char *auxiliar;
    int palabras = 0;

    cout << "Ingrese su texto: ";
    cin.getline(cadena, 200);

    auxiliar = strtok(cadena, " ");

    while (auxiliar != NULL)
    {
        palabras++;
        auxiliar = strtok(NULL, " ");
    }

    cout << "Su texto contiene: " << palabras;

    return 0;
}
