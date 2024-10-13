#include <iostream>

#define size 5

using std::cin;
using std::cout;
using std::endl;
using std::string;

int rellenar(string, string[]);

int main(int argc, char const *argv[])
{
    string vectorC[size] = {"AM001", "SD023", "JK015", "ES045", "BN121"};
    string vectorJava[size] = {"RE032", "TY012", "BN121", "SD023", "KL067"};
    string vector[size];
    int index = 0;

    cout << "Estudiantes que reprobraron C" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << vectorC[i] << endl;
    }

    cout << "\nEstudiantes que reprobraron Java" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << vectorJava[i] << endl;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (vectorC[i] == vectorJava[j])
            {
                vector[index++] = vectorC[i];
                break;
            }
        }
    }

    cout << "\nEstudiantes que reprobraron ambas" << endl;

    for (int i = 0; i < index; i++)
    {
        cout << vector[i] << endl;
    }

    return 0;
}
