#include <iostream>
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

// Função para calcular o valor de e
double calculadora(int termos) {
    double e = 1.0;
    for (int i = 1; i <= termos; ++i) {
        e += 1.0 / fatorial(i);
    }
    return e;
}

int main() {
    int termos;
    cout << "Digite o número de termos para calcular o valor de e: ";
    cin >> termos;

    if (termos < 1) {
        cout << "Por favor, insira um número de termos positivo." << endl;
        return 1;
    }

    // Defina a precisão de saída para 15 dígitos
    cout << fixed << setprecision(15);

    // Calcula e imprime o valor de e
    double e = calculadora(termos);
    cout << "O valor de e com " << termos << " termos é: " << e << endl;

    return 0;
}
