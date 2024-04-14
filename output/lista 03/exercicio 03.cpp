#include <iostream>
using namespace std;

int ehPalindromo(int numero) {
    int reverso = 0;
    int numerotemporario = numero;

    // Calculando o inverso do número
    while (numerotemporario > 0) {
        reverso = reverso * 10 + numerotemporario % 10;
        numerotemporario /= 10;
    }

    // Verificando se o número original é igual ao inverso
    return reverso == numero;
}

int main() {
    int numero;

    cout << "Digite um numero de 5 digitos: ";
    cin >> numero;

    if (numero < 10000 || numero > 99999) {
        cout << "O numero digitado nao possui 5 digitos." << endl;
        return 1; // Encerra o programa com código de erro
    }

    if (ehPalindromo(numero)) {
        cout << "O numero " << numero << " e um palindromo." << endl;
    } else {
        cout << "O numero " << numero << " nao e um palindromo." << endl;
    }

    return 0;
}

