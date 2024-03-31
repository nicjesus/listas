#include <iostream>
using namespace std;

int main() {

    int numero;
    bool ehPrimo = true;

    cout << "Digite um numero inteiro: ";
    cin >> numero;

    if (numero <= 1) {
        cout << "O numero " << numero << " nao e primo." << endl;
        return 0;
    }

    for (int i = 2; i <= numero / 2; ++i) {
        if (numero % i == 0) {
            ehPrimo = false;
            break;
        }
    }

    if (ehPrimo)
        cout << "O numero " << numero << " e primo." << endl;
    else
        cout << "O numero " << numero << " nao e primo." << endl;

    return 0;
}
