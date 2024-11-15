#include <iostream>
#include <cmath>

using namespace std;

const float pi = 3.141593;

union Coordenadas
{
    struct
    {
        float x;
        float y;
    } cartesiano;

    struct
    {
        float radio;
        float angulo;
    } polar;
};

void toPolar(const Coordenadas &coordenada, float &radio, float &angulo);
void toCartesiano(const Coordenadas &coordenada, float &x, float &y);

int main(int argc, char const *argv[])
{
    Coordenadas coordenada;
    int op;

    cout << "Seleccione el sistema de coordenadas" << endl;
    cout << "1. Cartesiano (x, y)" << endl;
    cout << "2. Polar (radio, angulo)" << endl;
    cout << "Seleccione: ";
    cin >> op;

    switch (op)
    {
    case 1:
        cout << "Ingrese las coordenadas x e y: ";
        cin >> coordenada.cartesiano.x >> coordenada.cartesiano.y;
        cout << "Coordenadas ingresadas en el sistema cartesiano" << endl;
        cout << "X = " << coordenada.cartesiano.x << endl;
        cout << "Y = " << coordenada.cartesiano.y << endl;

        float radio, angulo;
        toPolar(coordenada, radio, angulo);
        cout << "Trasformada a polar: (" << radio << ", " << angulo << ")" << endl;

        break;
    case 2:
        cout << "Ingrese el randio y el angulo: ";
        cin >> coordenada.polar.radio >> coordenada.polar.angulo;
        cout << "Coordenadas ingresadas en el sistema polar" << endl;
        cout << "R = " << coordenada.polar.radio << endl;
        cout << "Angulo = " << coordenada.polar.angulo << endl;

        float x, y;
        toCartesiano(coordenada, x, y);
        cout << "Trasformada a polar: (" << x << ", " << y << ")" << endl;

        break;

    default:
        cout << "Opcion no valida" << endl;
        break;
    }
    return 0;
}

void toPolar(const Coordenadas &coordenada, float &radio, float &angulo)
{
    radio = sqrt(pow(coordenada.cartesiano.x, 2) + pow(coordenada.cartesiano.y, 2));
    angulo = atan2(coordenada.cartesiano.y, coordenada.cartesiano.x) * 180 / pi;
}

void toCartesiano(const Coordenadas &coordenada, float &x, float &y)
{
    x = coordenada.polar.radio * cos(coordenada.polar.angulo * pi / 180);
    y = coordenada.polar.radio * sin(coordenada.polar.angulo * pi / 180);
}
