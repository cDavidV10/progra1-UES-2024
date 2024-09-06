// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    char nombres[5][100], mensajeFinal[100] = "", nickname[6] = "";
    int nombreSize;

    cout << "Digite 5 nombres: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Escriba el nombre " << i + 1 << " : ";
        cin.getline(nombres[i], 100);
    }

    for (int i = 0; i < 5; i++)
    {
        nombreSize = strlen(nombres[i]);
        strcpy(mensajeFinal, "");

        if (nombreSize < 5)
        {
            strcat(mensajeFinal, "Hola ");
            strcat(mensajeFinal, nombres[i]);
            strcat(mensajeFinal, ".Buenos dias. Su nombre tiene ");

            cout << mensajeFinal << nombreSize << " letras" << endl;
        }
        else
        {
            strncpy(nickname, nombres[i], 5);
            nickname[5] = '\0';

            strcat(mensajeFinal, "Hola ");
            strcat(mensajeFinal, nickname);
            strcat(mensajeFinal, ".Buenos dias. Su nombre tiene ");

            cout << mensajeFinal << nombreSize << " letras" << endl;
        }
    }

    return 0;
}
