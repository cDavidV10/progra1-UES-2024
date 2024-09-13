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

    cout << "Ingrese su texto: ";
    cin.getline(cadena, 200);

    for (int i = 0; i < strlen(cadena); i++)
    {

        if (isupper(cadena[i]))
        {
            cadena[i] = tolower(cadena[i]);
        }

        else if (islower(cadena[i]))
        {
            cadena[i] = toupper(cadena[i]);
        }
    }

    cout << cadena;

    return 0;
}
