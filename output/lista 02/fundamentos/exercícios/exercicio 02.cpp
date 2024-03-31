#include <iostream>
using namespace std;

int main() {
    
    double numero1, numero2;

   
    cout << "Digite o primeiro numero: ";
    cin >> numero1;
    cout << "Digite o segundo numero: ";
    cin >> numero2;

   
    double soma = numero1 + numero2;
    cout << "Soma: " << soma << endl;

    double produto = numero1 * numero2;
    cout << "Produto: " << produto << endl;

   
    double diferenca = numero1 - numero2;
    cout << "Diferença: " << diferenca << endl;

    
    if (numero2 != 0) {
    
        double quociente = numero1 / numero2;
        cout << "Quociente: " << quociente << endl;
    } else {
        cout << "Não é possível dividir por zero." << endl;
    }

    return 0;
}
