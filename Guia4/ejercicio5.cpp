// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>
#include <limits>
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;
using std::string;

void menu();
int leer();
void ordenar();
void impresion(string[], int[]);
void gotoxy(int, int);

const int size = 7;
int opcion = 0;
string dias[size] = {"Lunes", "Martes", "Miercoles", "Jueves", "Virnes", "Sabado", "Domimgo"};
int temperaturas[size] = {30, 29, 30, 32, 30, 31, 32};

int main(int argc, char const *argv[])
{
    do
    {
        menu();

        switch (opcion)
        {
        case 1:
            impresion(dias, temperaturas);
            system("pause");
            break;
        case 2:
            ordenar();
            system("pause");
            break;

        default:
            break;
        }
    } while (opcion != 3);

    cout << "Gracias por usar nuestro sistema :)";

    return 0;
}

void menu()
{
    system("cls");
    cout << "*****  MENU    *****" << endl;
    cout << "1. Tempratura por dia" << endl;
    cout << "2. Temperatura ordenada de menor a mayor" << endl;
    cout << "3. Salir" << endl;
    cout << "Selecione una opcion: ";
    opcion = leer();
}

int leer()
{
    int numero;

    while (true)
    {
        cin >> numero;

        if (cin.fail())
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

//* Ordenar Insercion
void ordenar()
{
    string diasOrdenados[size];
    int temperaturaOrdenada[size];
    string diaAux;
    int tempAux;
    int pos;

    for (int i = 0; i < size; i++)
    {
        diasOrdenados[i] = dias[i];
        temperaturaOrdenada[i] = temperaturas[i];
    }

    for (int i = 0; i < size; i++)
    {
        pos = i;
        diaAux = diasOrdenados[i];
        tempAux = temperaturaOrdenada[i];

        while (pos > 0 && tempAux < temperaturaOrdenada[pos - 1])
        {
            diasOrdenados[pos] = diasOrdenados[pos - 1];
            temperaturaOrdenada[pos] = temperaturaOrdenada[pos - 1];
            pos--;
        }

        diasOrdenados[pos] = diaAux;
        temperaturaOrdenada[pos] = tempAux;
    }

    impresion(diasOrdenados, temperaturaOrdenada);
}

void impresion(string dia[], int temperatura[])
{
    int promedio = 0;

    for (int i = 0; i < size; i++)
    {
        promedio += temperatura[i];
    }

    promedio /= size;

    gotoxy(10, 6);
    cout << "TEMPERATURAS";
    gotoxy(0, 7);
    cout << "Dia";
    gotoxy(15, 7);
    cout << "Temperatura";

    for (int i = 0; i < size; i++)
    {
        gotoxy(0, i + 8);
        cout << dia[i];
        gotoxy(15, i + 8);
        cout << temperatura[i] << " grados centigrados";
    }

    cout << endl;
    cout << "El promedio de temperatura es: " << promedio << " grados centigrados" << endl;
}

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}