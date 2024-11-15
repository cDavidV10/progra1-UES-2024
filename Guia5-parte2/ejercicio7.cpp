#include <iostream>
#include <fstream>

using namespace std;

union Peso
{
    float gramos;
    float kilogramos;
};

int main()
{
    Peso peso;

    cout << "Ingrese el peso del objeto en gramos: ";
    cin >> peso.gramos;

    FILE *archivo = fopen("peso.txt", "w");
    if (archivo == NULL)
    {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return 1;
    }
    fprintf(archivo, "%.2f\n", peso.gramos);
    fclose(archivo);

    archivo = fopen("peso.txt", "r");
    if (archivo == NULL)
    {
        cerr << "No se pudo abrir el archivo para leer." << endl;
        return 1;
    }
    fscanf(archivo, "%f", &peso.gramos);
    cout << "Peso en gramos: " << peso.gramos << " g" << endl;
    fclose(archivo);

    peso.kilogramos = peso.gramos / 1000.0;

    cout << "Peso en kilogramos: " << peso.kilogramos << " kg" << endl;

    return 0;
}
