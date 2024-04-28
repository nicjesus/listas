#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Função para gerar dois números inteiros aleatórios de um dígito
void gerar_numeros(int &num1, int &num2) {
    num1 = rand() % 10; // Número aleatório entre 0 e 9
    num2 = rand() % 10;
}

// Função para exibir uma pergunta de multiplicação e verificar a resposta
void pergunta_multiplicacao() {
    int num1, num2, resposta;
    gerar_numeros(num1, num2);
    cout << "Quanto é " << num1 << " vezes " << num2 << "?" << std::endl;
    cin >> resposta;
    while (resposta != num1 * num2) {
        cout << "Não. Por favor, tente novamente." << std::endl;
        cin >> resposta;
    }
    cout << "Muito bom!" << std::endl;
}

int main() {
    srand(time(0)); // Inicializa a semente para gerar números aleatórios
    pergunta_multiplicacao(); // Gera a primeira pergunta
    return 0;
}
