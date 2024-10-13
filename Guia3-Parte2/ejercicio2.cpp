#include <iostream>
#include <limits>

#define tamanio 100

using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::streamsize;

int leer();
void menu(int &);
void add(int[], int &);
float mediaNumero(int[], int);
float medianaNumero(int[], int[], int);
void modaNumero(int[], int[], int, int &);

int main()
{
    int datos[tamanio], moda[tamanio], datosOrdenados[tamanio];
    int opcion, index = 0, cantidad = 0;
    float media, mediana;

    do
    {
        menu(opcion);

        switch (opcion)
        {
        case 1:
            add(datos, index);
            break;
        case 2:
            media = mediaNumero(datos, index);
            mediana = medianaNumero(datos, datosOrdenados, index);
            modaNumero(datos, moda, index, cantidad);

            cout << "Vector ordenado" << endl;

            for (int i = 0; i < index; i++)
            {
                cout << datosOrdenados[i] << "\t";
            }

            cout << "\nLa media es: " << media << endl;
            cout << "La mediana es: " << mediana << endl;
            cout << "Moda numero" << endl;

            for (int i = 0; i < cantidad; i++)
            {
                cout << moda[i] << "\t";
            }
            cout << endl;
            break;
        default:
            break;
        }
    } while (opcion != 3);

    cout << "Gracias por usar nuestro sistema" << endl;
    return 0;
}

void menu(int &opcion)
{
    cout << "1. Ingresar numeros enteros" << endl;
    cout << "2. Mostrar" << endl;
    cout << "3. Salir" << endl;

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

void add(int datos[], int &index)
{
    int respuesta = 0;
    bool validar = false;

    do
    {
        cout << "Agregando !!" << endl;
        cout << "Numero [" << (index + 1) << "]: ";
        datos[index++] = leer();

        do
        {
            cout << "Seguir agredando? 1 -> si 2 -> no : ";
            respuesta = leer();

            validar = respuesta == 1 ? true : respuesta == 2 ? true
                                                             : false;
        } while (!validar);

    } while (respuesta == 1);

    system("cls");
}

float mediaNumero(int datos[], int index)
{
    float media = 0;

    for (int i = 0; i < index; i++)
    {
        media += datos[i];
    }

    media /= index;

    return media;
}

float medianaNumero(int datos[], int vector[], int index)
{
    int auxiliar;
    float mediana;

    for (int i = 0; i < index; i++)
    {
        vector[i] = datos[i];
    }

    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                auxiliar = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = auxiliar;
            }
        }
    }

    if (index % 2 == 0)
    {
        mediana = (vector[index / 2 - 1] + vector[index / 2]) / 2.00;
    }
    else
    {
        mediana = vector[index / 2];
    }

    return mediana;
}

void modaNumero(int datos[], int vector[], int index, int &cantidad)
{
    int contador1 = 0, contador2 = 0;
    cantidad = 0;
    bool existe = false;

    for (int i = 0; i < index; i++)
    {
        contador1 = 1;

        for (int j = i + 1; j < index; j++)
        {
            if (datos[i] == datos[j])
            {
                contador1++;
            }
        }

        if (contador1 > contador2)
        {
            contador2 = contador1;
            vector[0] = datos[i];
            cantidad = 1;
        }

        else if (contador1 == contador2)
        {

            existe = false;
            for (int k = 0; k < cantidad; k++)
            {
                if (vector[k] == datos[i])
                {
                    existe = true;
                    break;
                }
            }
            if (!existe)
            {
                vector[cantidad++] = datos[i];
            }
        }
    }
}
