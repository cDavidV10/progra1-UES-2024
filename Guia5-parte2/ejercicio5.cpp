#include <iostream>

using namespace std;

union Calificacion
{
    int notaEntera;
    char notaLetra;
};

int main()
{
    Calificacion calificacion;
    int opcion;

    cout << "Seleccione el tipo de calificacion a ingresar" << endl;
    cout << "1. Nota en numero entero" << endl;
    cout << "2. Nota en letra (A, B, C, F)" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        cout << "Ingrese la calificacion en numero entero: ";
        cin >> calificacion.notaEntera;
        cout << "Nota almacenada: " << calificacion.notaEntera << endl;
        break;

    case 2:
        cout << "Ingrese la calificacion como letra (A, B, C, F): ";
        cin >> calificacion.notaLetra;
        cout << "Nota almacenada: " << calificacion.notaLetra << endl;
        break;

    default:
        cout << "Opcion no valida.\n";
        break;
    }

    return 0;
}
