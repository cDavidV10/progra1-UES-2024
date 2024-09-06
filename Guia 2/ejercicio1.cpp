// Carlos David Vásquez Rivas   VR24001

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string cadenas[3], cadenaConcatenada;
    int limite;

    limite = sizeof(cadenas) / sizeof(cadenas[0]);

    for (int i = 0; i < limite; i++)
    {
        cout << "Digite su texto " << i + 1 << ": ";
        getline(cin, cadenas[i]);
    }

    cout << "Su primera cadena tiene una longitud de: " << cadenas[0].size() << endl;

    if (cadenas[0].size() > 10)
    {
        cadenaConcatenada = cadenas[0] + " " + cadenas[1];
    }
    else
    {
        cadenaConcatenada = cadenas[0] + " " + cadenas[2];
    }
    cout << cadenaConcatenada;

    return 0;
}
