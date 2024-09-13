// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    char cadena[100];

    cout << "Escriba su texto: ";
    cin.getline(cadena, 100);

    for (int i = 0; i < strlen(cadena); i++)
    {
        if (i == 0)
        {
            cadena[i] = toupper(cadena[i]);
        }

        if (i > 0)
        {
            if (cadena[i - 1] == ' ')
            {
                cadena[i] = toupper(cadena[i]);
            }
        }
    }

    cout << cadena;

    return 0;
}
