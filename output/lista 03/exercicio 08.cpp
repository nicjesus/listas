#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double numero1, numero2;
    char operacao;

    // Solicita a entrada dos dois números
    cout << "Digite o primeiro numero: ";
    cin >> numero1;
    cout << "Digite o segundo numero: ";
    cin >> numero2;

    // Solicita a entrada do operador
    cout << "Digite o operador (+, -, * ou /): ";
    cin >> operacao;

    // Realiza a operação com base no operador inserido
    switch (operacao) {
        case '+':
            cout << "Resultado: " << fixed << setprecision(2) << numero1 + numero2 << endl;
            break;
        case '-':
            cout << "Resultado: " << fixed << setprecision(2) << numero1 - numero2 << endl;
            break;
        case '*':
            cout << "Resultado: " << fixed << setprecision(2) << numero1 * numero2 << endl;
            break;
        case '/':
            if (numero2 != 0) {
                cout << "Resultado: " << fixed << setprecision(2) << numero1 / numero2 << endl;
            } else {
                cout << "Erro! A divisao por zero nao e permitida." << endl;
            }
            break;
        default:
            cout << "Operador invalido!" << endl;
            break;
    }

    return 0;
}
