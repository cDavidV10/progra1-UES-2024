// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int conversor(string);
bool validacion(int, int, int);
bool es_bisiesto(int);

int main()
{
    char fecha[50];
    char *auxiliar;
    string resultado[3];
    string meses[12] = {"Enero", "Febrero", "Marzo",
                        "Abril", "Mayo", "Junio",
                        "Julio", "Agosto", "Septiembre", "Octubre",
                        "Noviembre", "Diciembre"};
    int index = 0, limite, dia, mes, year;

    cout << "\t\t\t Transformador de fecha" << endl;
    cout << "Escriba su fecha en esta forma: dia/numero de mes/ano" << endl;

    cout << "Escriba su fecha: ";
    gets(fecha);

    auxiliar = strtok(fecha, "/");

    while (auxiliar != NULL)
    {
        resultado[index++] = auxiliar;
        auxiliar = strtok(NULL, "/");
    }

    dia = conversor(resultado[0]);
    mes = conversor(resultado[1]);
    year = conversor(resultado[2]);

    if (mes < 1 || mes > 12)
    {
        cout << "El mes debe estar entre 1 y 12." << endl;
        return 1; // Error en el mes
    }

    // Validar la fecha
    if (validacion(dia, mes, year))
    {
        cout << "Su fecha es: " << dia << " de " << meses[mes - 1] << " de " << year << endl;
    }
    else
    {
        cout << "Fecha invalida." << endl;
    }
    return 0;
}

bool es_bisiesto(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int conversor(string fecha)
{
    int valor;

    valor = stoi(fecha);

    return valor;
}

bool validacion(int dia, int mes, int year)
{
    int limite;

    switch (mes)
    {
    case 2:
        limite = es_bisiesto(year) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        limite = 30;
        break;
    default:
        limite = 31;
        break;
    }

    if (dia < 1 || dia > limite)
    {
        return false;
    }

    return true;
}
