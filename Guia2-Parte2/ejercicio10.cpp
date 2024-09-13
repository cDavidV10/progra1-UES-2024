// Carlos David Vásquez Rivas   VR24001
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[])
{
    string cadena;

    cout << "Combinancion de 3 caracteres" << endl;

    do
    {
        cout << "Ingrese unicamente 3 letras y/o caracteres: ";
        getline(cin, cadena);
    } while (cadena.size() != 3);

    for (int i = 0; i < cadena.size(); i++)
    {
        for (int j = 0; j < cadena.size(); j++)
        {
            if (i == j)
                continue;
            for (int k = 0; k < cadena.size(); k++)
            {
                if (j == k || k == i)
                    continue;
                cout << cadena[i] << cadena[j] << cadena[k] << "\t";
            }
        }
    }

    return 0;
}
