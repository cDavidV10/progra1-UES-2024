// Carlos David Vásquez Rivas   VR24001
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    char cadena[200], salida[200] = "";
    char *auxiliar;

    cout << "Ingrese su texto: ";
    cin.getline(cadena, 200);

    auxiliar = strtok(cadena, " ");

    while (auxiliar != NULL)
    {
        strcat(salida, auxiliar);
        strcat(salida, " ");
        auxiliar = strtok(NULL, " ");
    }

    cout << "Su texto es: " << salida;

    return 0;
}
