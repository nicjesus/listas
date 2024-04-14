#include <iostream>
using namespace std;

int main() {
    
    int numero1, numero2;
    //o usuário digitará um número inteiro
    cout << "Digite o primeiro numero inteiro: ";
    cin >> numero1;
    //o usuário digitará um número inteiro
    cout << "Digite o segundo numero inteiro: ";
    cin >> numero2;

    if (numero1 % numero2 == 0) {
        cout << numero1 << " é um multiplo de " << numero2 << endl;
    } else {
        cout << numero1 << " não é um multiplo de " << numero2 << endl;
    }
//o código retornará se o numero1 é múltiplo ou não do número2
    return 0;
}
