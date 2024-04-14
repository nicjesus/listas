#include <iostream>
using namespace std;

int main() {
    cout << "Pense em um número entre 1 e 100 e eu tentarei adivinhá-lo em até sete tentativas." << endl;

    int minimo = 1;
    int maximo = 100;
    int tentativas = 0;

    // Loop para fazer as tentativas
    while (true) {
        // Calcula o palpite
        int palpite = (minimo + maximo) / 2;

        // Pergunta ao usuário se o palpite é o número que ele está pensando
        cout << "O número em que você está pensando é menor que " << palpite << "? (s/n): ";
        char resposta;
        cin >> resposta;

        // Incrementa o número de tentativas
        tentativas++;

        // Verifica a resposta do usuário
        if (resposta == 's') {
            // Se o palpite for menor que o número, ajusta o limite superior
            maximo = palpite - 1;
        } else if (resposta == 'n') {
            // Se o palpite for maior que o número, ajusta o limite inferior
            minimo = palpite + 1;
        } else {
            // Se a resposta não for 's' nem 'n', solicita que o usuário responda novamente
            cout << "Por favor, responda 's' para sim ou 'n' para não." << endl;
            continue;
        }

        // Verifica se o palpite é igual ao número
        if (minimo > maximo) {
            cout << "Não é possível adivinhar o número. Você deve ter cometido um erro." << endl;
            break;
        } else if (minimo == maximo) {
            cout << "O número que você está pensando é: " << minimo << endl;
            cout << "Número de tentativas: " << tentativas << endl;
            break;
        }
    }

    return 0;
}
