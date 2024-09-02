// Carlos David Vásquez Rivas VR24001

#include <iostream>
#include <ctime>
#include <conio.h>

using std::cin;
using std::cout;
using std::endl;

int randomNumber();
bool nuevaTirada(int);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int dado1, dado2, puntaje;
    float apuesta, ganancia;
    int saldoInicial = 10;
    char respuesta, seguir;

    cout << "\t\t\t\t\t JUEGO CRAPS" << endl;

    cout << "BIENVENIDOS" << endl;

    do
    {
        if (saldoInicial == 0)
        {
            cout << "TE HAS QUEDADO SIN DINERO :(" << endl;
            break;
        }
        else
        {
            do
            {
                cout << "Estas listo para jugar (s/n): ";
                cin.get(respuesta);
                cin.ignore();
            } while (respuesta == 'n' || respuesta == 'N');

            system("cls");
            do
            {
                system("cls");
                cout << "Tu saldo inical es de: $" << saldoInicial << endl;
                cout << "Cuantos deseas apostar: $";
                cin >> apuesta;

            } while (apuesta > saldoInicial);

            saldoInicial -= apuesta;

            dado1 = randomNumber();
            cout << "El dado 1 es: " << dado1 << endl;

            dado2 = randomNumber();
            cout << "El dado 2 es: " << dado2 << endl;

            puntaje = dado1 + dado2;

            cout << "Tu puntaje es: " << puntaje << endl;

            if (puntaje == 7 || puntaje == 11)
            {
                ganancia = apuesta * 2;
                saldoInicial += ganancia;
                cout << "Felicidades, has ganado $" << ganancia << endl;
            }
            else if (puntaje == 2 || puntaje == 3 || puntaje == 12)
            {
                cout << "Has perdido :(" << endl;
            }
            else
            {
                cout << "Ganaste una nueva tirada" << endl;
                if (nuevaTirada(puntaje)) // TODO -> TRUE
                {
                    ganancia = apuesta * 2;
                    saldoInicial += ganancia;
                    cout << "Felicidades, has ganado $" << ganancia << endl;
                }
                else
                {
                    cout << "Has perdido :(" << endl;
                }
            }

            cin.ignore();
            cout << "Deseas continuar (s/n): ";
            cin.get(seguir);

            system("cls");
        }

    } while (seguir == 's' || seguir == 'S');

    cout << "Tu saldo final es: $" << saldoInicial << endl;
    cout << "\t\t\t\t\t GRACIAS POR JUEGAR" << endl;

    return 0;
}

int randomNumber()
{
    int randomNumber;

    randomNumber = 1 + rand() % 6;

    return randomNumber;
}

bool nuevaTirada(int puntaje)
{
    int nuevoPuntaje, dado1, dado2;

    do
    {
        cout << "Para ganar necesitas sacar: " << puntaje << endl;
        cout << "Pierdes si sacas 7" << endl;

        dado1 = randomNumber();
        cout << "El dado 1 es: " << dado1 << endl;

        dado2 = randomNumber();
        cout << "El dado 2 es: " << dado2 << endl;

        nuevoPuntaje = dado1 + dado2;
        cout << "Tu nuevo puntaje es: " << nuevoPuntaje << endl;

        if (nuevoPuntaje == 7)
        {
            return false;
        }
        else if (nuevoPuntaje == puntaje)
        {
            return true;
        }

        cout << "Presiona cualquier tecla para continuar...";
        _getch();
        system("cls");

    } while (true);
}
