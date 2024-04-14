#include <iostream>
#include <cmath> 
#include <iomanip>
using namespace std;

// Função para calcular o fatorial
double fatorial(int n) {
    double resultado = 1;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

// Função para calcular o operador1
double calculadora(double x, int termos) {
    double operador1 = 1.0;
    double operador2 = 1.0;
    for (int i = 1; i <= termos; ++i) {
        operador2 *= x;
        operador1 += operador2 / fatorial(i);
    }
    return operador1;
}

int main() {
    double x;
    int termos;

    cout << "Digite o valor de x para calcular ex: ";
    cin >> x;

    cout << "Digite o número de termos para a série de Taylor: ";
    cin >> termos;

    // Defina a precisão de saída para 10 dígitos
    cout << fixed << setprecision(10);

    double operador1 = calculadora(x, termos);
    cout << "O valor de e^" << x << " com " << termos << " termos é: " << operador1 << endl;

    return 0;
}
