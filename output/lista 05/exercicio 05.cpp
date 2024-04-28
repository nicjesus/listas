#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Inicializa a semente para gerar números aleatórios
    char jogar_novamente;

    do {
        int numero_secreto = rand() % 1000 + 1; // Gera o número aleatório entre 1 e 1000
        int palpite;
        cout << "Eu tenho um número entre 1 e 1000." << std::endl;
        cout << "Você consegue adivinhar o meu número?" << std::endl;

        // Loop para permitir múltiplos palpites
        do {
            cout << "Digite seu palpite: ";
            cin >> palpite;

            if (palpite == numero_secreto) {
                cout << "Excelente! Você adivinhou o número!" << std::endl;
                break; // Sai do loop se o palpite estiver correto
            } else if (palpite < numero_secreto) {
                cout << "Muito baixo. Tente novamente." << std::endl;
            } else {
                cout << "Muito alto. Tente novamente." << std::endl;
            }
        } while (true);

        // Pergunta ao jogador se ele deseja jogar novamente
        cout << "Você gostaria de jogar novamente (s ou n)? ";
        cin >> jogar_novamente;
    } while (jogar_novamente == 's');

    return 0;
}
