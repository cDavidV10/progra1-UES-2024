#include <iostream>
#include <cstring>

using namespace std;

struct DeporteEquipo
{
    char nombre[50];
    int numeroJugadores;
};

struct DeporteIndividual
{
    char nombre[50];
    char tipoCompeticion[50];
};

union Deporte
{
    DeporteEquipo equipo;
    DeporteIndividual individual;
};

int main()
{
    Deporte deporte;
    int opcion;

    cout << "Seleccione el tipo de deporte que desea registrar" << endl;
    cout << "1. Deporte de equipo" << endl;
    cout << "2. Deporte individual" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    cin.ignore();
    if (opcion == 1)
    {
        cout << "Ingrese el nombre del deporte de equipo: ";
        cin.getline(deporte.equipo.nombre, 50);
        cout << "Ingrese el numero de jugadores en el equipo: ";
        cin >> deporte.equipo.numeroJugadores;
        cin.ignore();

        cout << "\nInformacion del deporte de equipo registrado" << endl;
        cout << "Deporte: " << deporte.equipo.nombre << endl;
        cout << "Numero de jugadores: " << deporte.equipo.numeroJugadores << endl;
    }
    else if (opcion == 2)
    {
        cout << "Ingrese el nombre del deporte individual: ";
        cin.getline(deporte.individual.nombre, 50);
        cout << "Ingrese el tipo de competicion: ";
        cin.getline(deporte.individual.tipoCompeticion, 50);

        cout << "\nInformacion del deporte individual registrado" << endl;
        cout << "Deporte: " << deporte.individual.nombre << endl;
        cout << "Tipo de competicion: " << deporte.individual.tipoCompeticion << endl;
    }
    else
    {
        cout << "Opcion no valida. El programa terminara.\n";
    }

    return 0;
}
