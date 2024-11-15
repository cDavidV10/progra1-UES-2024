#include <iostream>
#include <string>

using namespace std;

union Empleado
{
    int id;
    char nombre[50];
    float salario;
};

int main()
{
    Empleado empleado;
    int opcion;

    do
    {
        system("cls");
        cout << "\nSeleccione el campo que desea ingresar" << endl;
        cout << "1. Identificador (ID)" << endl;
        cout << "2. Nombre" << endl;
        cout << "3. Salario" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el identificador (ID) del empleado: ";
            cin >> empleado.id;
            cout << "Identificador registrado: " << empleado.id << endl;
            break;

        case 2:
            cout << "Ingrese el nombre del empleado: ";
            cin.ignore();
            cin.getline(empleado.nombre, 50);
            cout << "Nombre registrado: " << empleado.nombre << endl;
            break;

        case 3:
            cout << "Ingrese el salario del empleado: ";
            cin >> empleado.salario;
            cout << "Salario registrado: " << empleado.salario << endl;
            break;

        case 4:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opción no valida. Inténtelo de nuevo." << endl;
            break;
        }
        system("pause");

    } while (opcion != 4);

    return 0;
}
