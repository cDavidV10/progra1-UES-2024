// Carlos David Vásquez Rivas VR24001

#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

void leer(double coordenadas[], char ejes[]);
double perimetro(double puntoA[], double puntoB[], double puntoC[]);
double distancia(double punto1[], double punto2[]);
int main(int argc, char const *argv[])
{
    char ejes[3] = {'X', 'Y', 'Z'};
    double puntoA[3], puntoB[3], puntoC[3], resultado;

    cout << "Digite las coordenadas de su primer punto: " << endl;
    leer(puntoA, ejes);

    system("cls");

    cout << "Digite las coordenadas de su segundo punto: " << endl;
    leer(puntoB, ejes);

    system("cls");
    cout << "Digite las coordenadas de su tercer punto: " << endl;
    leer(puntoC, ejes);

    system("cls");

    resultado = perimetro(puntoA, puntoB, puntoC);

    cout << "El perimetro del triangulo es: " << resultado << endl;

    return 0;
}

void leer(double coordenadas[], char ejes[])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "Digite la coordenada " << ejes[i] << ": ";
        cin >> coordenadas[i];
    }
}

double distancia(double punto1[], double punto2[])
{
    int distancia;
    for (int i = 0; i < 3; i++)
    {
        distancia += pow(punto2[i] - punto1[i], 2);
    }

    return sqrt(distancia);
}

double perimetro(double puntoA[], double puntoB[], double puntoC[])
{
    int perimetro;

    perimetro = distancia(puntoA, puntoB) + distancia(puntoB, puntoC) + distancia(puntoC, puntoA);

    cout.precision(4);

    return perimetro;
}
