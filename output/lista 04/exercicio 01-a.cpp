#include <iostream>
using namespace std;

// Função para calcular o fatorial
void fatorial(int n) {
    int result[10000] = {0}; // Inicializa o resultado como 0
    result[0] = 1; // Define o primeiro dígito como 1
    int length = 1; // Comprimento inicial do resultado
    
    // Multiplica sequencialmente os números de 2 a n
    for (int i = 2; i <= n; ++i) {
        int soma = 0;
        // Multiplica cada dígito do resultado por i e adiciona a soma
        for (int j = 0; j < length; ++j) {
            int prod = result[j] * i + soma;
            result[j] = prod % 10; // Mantém apenas o dígito das unidades
            soma = prod / 10; // Calcula a soma
        }
        // Adiciona qualquer soma restante ao resultado
        while (soma) {
            result[length] = soma % 10;
            soma /= 10;
            ++length;
        }
    }
    
    // Imprime o resultado
    cout << "O fatorial de " << n << " é: ";
    for (int i = length - 1; i >= 0; --i) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Digite um número inteiro não negativo: ";
    cin >> num;
    
    if (num < 0) {
        cout << "Por favor, digite um número não negativo." << endl;
        return 1;
    }
    
    fatorial(num);
    
    return 0;
}