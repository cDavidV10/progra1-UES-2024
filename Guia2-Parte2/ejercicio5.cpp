// Carlos David Vásquez Rivas   VR24001

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

string mayus(string);

int main(int argc, char const *argv[])
{
    string nombres[100], nombre, year, carnet[100], auxiliar, year_individual;
    int index = 0, limite, ingresados = 0;
    int minimo = 0, maximo = 0;
    char respuesta;

    cout << "Creador de carnet" << endl;

    do
    {

        cout << "Digite el anio de ingreso: ";
        getline(cin, year);

        cout << "Digite los apellidos: ";
        getline(cin, nombre);

        nombre = mayus(nombre);
        nombres[index++] = year + " " + nombre;

        cout << "Desea continuar (s/n): ";
        cin >> respuesta;

        cin.ignore();
        system("cls");

        ingresados++;

    } while (respuesta == 's' || respuesta == 'S');

    for (int i = 0; i < ingresados; i++)
    {
        year_individual = nombres[i].substr(0, nombres[i].find(' '));

        minimo = nombres[i].find(' ') + 1;

        carnet[i] = "";

        for (int j = nombres[i].find(' ') + 1; j <= nombres[i].length(); j++)
        {
            if (nombres[i][j] == ' ' || nombres[i][j] == '\0')
            {
                maximo = j - minimo;
                if (j - minimo != 0)
                {
                    auxiliar = nombres[i].substr(minimo, maximo);

                    carnet[i] += auxiliar[0];
                }
                minimo = j + 1;
            }
        }
        carnet[i] += year_individual.substr(2, 2) + "00" + to_string(i + 1);

        cout << carnet[i] << endl;
    }

    return 0;
}

string mayus(string cadena)
{
    for (int i = 0; i < cadena.length(); i++)
    {
        cadena[i] = toupper(cadena[i]);
    }

    return cadena;
}
