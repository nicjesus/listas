#include <iostream>
#include <iomanip> // Para definir a precisão de saída

using namespace std;

// Função para converter Celsius para Fahrenheit
double celsius_para_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Função para imprimir a tabela
void imprimir_tabela() {
    cout << "Celsius\tFahrenheit" << endl;
    for (int celsius = 0; celsius <= 100; ++celsius) {
        double fahrenheit = celsius_para_fahrenheit(celsius);
        cout << fixed << setprecision(1) << celsius << "\t" << fahrenheit << endl;
    }
}

int main() {
    imprimir_tabela();
    return 0;
}
