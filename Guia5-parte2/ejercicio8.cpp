#include <iostream>
#include <cstring>

using namespace std;

union InfoAdicional
{
    char genero[30];
    float calificacion;
};

struct Cancion
{
    char titulo[50];
    char artista[50];
    float duracion;
    InfoAdicional info;
    bool esGenero;
};

int main()
{
    Cancion cancion;

    cout << "Ingrese el titulo de la cancion: ";
    cin.getline(cancion.titulo, 50);
    cout << "Ingrese el artista de la cancion: ";
    cin.getline(cancion.artista, 50);
    cout << "Ingrese la duracion de la cancion (en minutos): ";
    cin >> cancion.duracion;

    int opcion;
    cout << "Que tipo de informacion adicional desea ingresar?" << endl;
    cout << "1. Genero musical" << endl;
    cout << "2. Calificacion (de 1.0 a 5.0)" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();

    if (opcion == 1)
    {
        cout << "Ingrese el genero musical: ";
        cin.getline(cancion.info.genero, 30);
        cancion.esGenero = true;
    }
    else if (opcion == 2)
    {
        cout << "Ingrese la calificacion de la cancion (de 1.0 a 5.0): ";
        cin >> cancion.info.calificacion;
        cancion.esGenero = false;
    }
    else
    {
        cout << "Opcion no valida. Se asignara informacion por defecto.\n";
        cancion.esGenero = true;
        strcpy(cancion.info.genero, "Desconocido");
    }

    cout << "Informacion de la cancion registrada:\n";
    cout << "Titulo: " << cancion.titulo << endl;
    cout << "Artista: " << cancion.artista << endl;
    cout << "Duracion: " << cancion.duracion << " minutos" << endl;

    if (cancion.esGenero)
    {
        cout << "Genero musical: " << cancion.info.genero << endl;
    }
    else
    {
        cout << "Calificacion: " << cancion.info.calificacion << "/5.0" << endl;
    }

    return 0;
}
