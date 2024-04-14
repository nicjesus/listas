#include <iostream>
using namespace std;

int main() {
    int numeros[5];

    // Solicita ao usuário que insira cinco números entre 1 e 30
    cout << "Digite cinco números entre 1 e 30:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Número " << i + 1 << ": ";
        cin >> numeros[i];

        // Verifica se o número está dentro do intervalo permitido
        if (numeros[i] < 1 || numeros[i] > 30) {
            cout << "Por favor, digite um número entre 1 e 30." << endl;
            --i; // Volta uma iteração para permitir que o usuário insira o número novamente
        }
    }

    // Exibe as barras de asteriscos para cada número lido
    cout << "\nBarras de asteriscos:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Número " << i + 1 << ": ";
        // Imprime o número de asteriscos correspondente ao valor do número lido
        for (int j = 0; j < numeros[i]; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
