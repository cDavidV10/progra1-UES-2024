#include <iostream>
#include <cmath>

using namespace std;

union Moneda
{
    double dolar;
    double euro;
};

void leeMoneda(int);
void guardarMoneda(Moneda moneda, int tipo);

int main(int argc, char const *argv[])
{
    Moneda moneda;
    int tipo;

    do
    {
        cout << "-----   DIVISAS     -----" << endl;
        cout << "1. Dolar USD" << endl;
        cout << "2. Euro  EUR" << endl;
        cout << "Seleccione: ";
        cin >> tipo;

        switch (tipo)
        {
        case 1:
            cout << "Ingrese la cantidad de dolares: ";
            cin >> moneda.dolar;
            guardarMoneda(moneda, tipo);
            break;
        case 2:
            cout << "Ingrese la cantidad de Euros: ";
            cin >> moneda.euro;
            guardarMoneda(moneda, tipo);
            break;

        default:
            cout << "Opcion invalida, intente de nuevo" << endl;
            break;
        }
    } while (tipo < 1 || tipo > 2);

    cout << "Divisa almacenda: " << endl;
    leeMoneda(tipo);

    return 0;
}

void guardarMoneda(Moneda moneda, int tipo)
{
    FILE *archivo = fopen("moneda.txt", "w");

    if (archivo == NULL)
    {
        cout << "Hubo un error, no exite el archivo";
        exit(1);
    }

    if (tipo == 1)
    {
        fprintf(archivo, "USD %.2f\n", moneda.dolar);
    }
    else
    {
        fprintf(archivo, "EUR %.2f\n", moneda.euro);
    }

    fclose(archivo);
}

void leeMoneda(int tipo)
{
    FILE *archivo = fopen("moneda.txt", "r");

    if (archivo == NULL)
    {
        cout << "Hubo un error, no exite el archivo";
        exit(1);
    }

    char divisa[4];
    float valor;

    fscanf(archivo, "%s %f", divisa, &valor);

    if ((tipo == 1) && (divisa[0] == 'U') || (tipo == 2) && (divisa[0] == 'E'))
    {
        cout << "La divisa recuperada es: " << divisa << " " << valor << endl;
    }
    else
    {
        cout << "Hubo un error en la lectura de la devisa" << endl;
    }

    fclose(archivo);
}
