#include <iostream>
using namespace std;

int main() {
    double raio, diametro, area;
    const double pi = 3.14159;

    cout << "Digite o raio do circulo: ";
    cin >> raio;

    diametro = 2 * raio;

    area = pi * raio * raio;

    cout << "Diametro: " << diametro << endl;
    cout << "Area: " << area << endl;

    return 0;
}
