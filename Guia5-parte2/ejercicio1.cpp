// Carlos David Vásquez Rivas    VR24001

#include <iostream>

using namespace std;

union Temperatura
{
    float celsius;
    float fahrenheit;
};

int main()
{
    Temperatura temp;

    cout << "Ingrese la temperatura en grados Celsius: ";
    cin >> temp.celsius;

    temp.fahrenheit = (temp.celsius * 9.0 / 5.0) + 32.0;

    cout << "Temperatura en Fahrenheit: " << temp.fahrenheit << " F" << endl;

    return 0;
}
