// Carlos David Vásquez Rivas   VR24001

#include <iostream>
#include <cstring>
#include <conio.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void singUp(string &, string &);
void singIn(string, string);

int main(int argc, char const *argv[])
{
    string user, password;
    int option;

    do
    {
        cout << "1. Registrarse" << endl;
        cout << "2. Iniciar Sesion" << endl;
        cout << "3. Salir" << endl;
        cin >> option;

        cin.ignore();

        switch (option)
        {
        case 1:
            singUp(user, password);

            cout << "Cuenta creada con exito" << endl;
            cout << "Presiona cualquier tecla para continuar...";
            _getch();
            break;

        case 2:
            singIn(user, password);
            cout << "Presiona cualquier tecla para continuar...";
            _getch();
            break;
        }

        system("cls");
    } while (option != 3);

    cout << "Gracias por usar nuestros servicios, vuelva pronto";

    return 0;
}

void singUp(string &user, string &password)
{

    cout << "Crea tu cuenta" << endl;

    cout << "Usuario: ";
    getline(cin, user);

    cout << "Contrasenia: ";
    getline(cin, password);
}

void singIn(string user, string password)
{
    string usuario, contrasenia;
    int intentos = 0;

    cout << "Inicia Sesion" << endl;

    do
    {
        cout << "Ingrese su usuario: ";
        getline(cin, usuario);

        cout << "Ingrese su contrasenia: ";
        getline(cin, contrasenia);

        if (usuario == user && contrasenia == password)
        {
            cout << "Bienvenido " << user << endl;
            break;
        }
        else
        {
            cout << "Usuario o contrasenia erroneo" << endl;

            intentos++;
        }
    } while (intentos < 3);

    if (intentos == 3)
    {
        cout << "Intentos maximos alcanzados" << endl;
    }
}
