// Carlos David Vásquez Rivas VR24001

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    int divisorA, divisorB, residuo, mcd, auxiliar;

    cout << "Digite su primer: ";
    cin >> divisorA;
    cout << "Digite su segundo: ";
    cin >> divisorB;

    if (divisorB == 0)
    {
        cout << "No se pude realizar la operacion";
        return 0;
    }

    residuo = divisorA % divisorB;
    do
    {
        if (residuo == 0)
        {
            mcd = divisorB;

            cout << "El mcd es: " << mcd;
            return 0;
        }

        auxiliar = residuo;
        residuo = divisorB % auxiliar;
        mcd = auxiliar;
    } while (residuo != 0);

    cout << "El mcd es: " << mcd;

    return 0;
}
