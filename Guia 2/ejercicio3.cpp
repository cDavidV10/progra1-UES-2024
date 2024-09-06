// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    char cadena[200], cadenaSinEspacio[200] = "";
    char *auxiliar;
    cout << "\t\t Eliminar los espacios de una cadena" << endl;

    cout << "Digite su texto: ";
    gets(cadena);

    cout << "Su texto es: " << cadena << endl;
    auxiliar = strtok(cadena, " ");

    while (auxiliar != NULL)
    {
        strcat(cadenaSinEspacio, auxiliar);
        auxiliar = strtok(NULL, " ");
    }

    cout << "Su texto sin espcio es: " << cadenaSinEspacio;

    return 0;
}
