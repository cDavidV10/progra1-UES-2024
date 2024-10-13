// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <string>
#include <limits>

#define size 3

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;

float promedio(string);
float leer();

int main(int argc, char const *argv[])
{
    string nombre, carnet;
    float mate, progra, historia, cum;

    cout << "Datos del Estudiante" << endl;

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Carnet: ";
    getline(cin, carnet);

    mate = promedio("Mate II");
    progra = promedio("Progra I");
    historia = promedio("Historia");

    cum = (mate + progra + historia) / 3;

    cout.precision(3);

    cout << "\t\t-------------------------------" << endl;
    cout << "\t\t Materia          | Promedio  " << endl;
    cout << "\t\t-------------------|-----------" << endl;
    cout << "\t\t| Matematica II    | " << mate << endl;
    cout << "\t\t| Programacion I   | " << progra << endl;
    cout << "\t\t| Historia         | " << historia << endl;
    cout << "\t\t--------------------------------" << endl;
    cout << "\t\t   CUM: " << cum << endl;
    cout << "\t\t--------------------------------" << endl;

    if (cum > 5.95)
    {
        cout << "\t\t Aprobado" << endl;
    }
    else
    {
        cout << "\t\t Desaprobado" << endl;
    }

    return 0;
}

float promedio(string materia)
{
    float promedio = 0;
    float notas[size];
    cout << "Ingrese las notas de " << materia << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Ingrese la nota " << i + 1 << ": ";
        notas[i] = leer();

        promedio += notas[i];
    }

    return promedio / size;
}

float leer()
{
    float numero;

    while (true)
    {
        cin >> numero;

        if (cin.fail() || numero < 0 || numero > 10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Dato Incorrecto, ingrese el dato nuevamente: ";
        }
        else
        {
            break;
        }
    }
    return numero;
}