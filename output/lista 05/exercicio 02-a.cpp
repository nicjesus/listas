#include <iostream>
using namespace std;

bool is_prime(int number) {
    // Um número inteiro menor ou igual a 1 não é primo
    if (number <= 1) {
        return false;
    }

    // Percorre todos os números de 2 até a metade do número
    for (int i = 2; i <= number / 2; ++i) {
        // Se o número for divisível por algum outro número que não seja 1 ou ele próprio, não é primo
        if (number % i == 0) {
            return false;
        }
    }

    // Se nenhum número além de 1 e ele próprio divide o número, então é primo
    return true;
}

int main() {
    // Testando a função com alguns exemplos
    cout << "2 é primo? " << (is_prime(2) ? "Sim" : "Não") << std::endl;
    cout << "3 é primo? " << (is_prime(3) ? "Sim" : "Não") << std::endl;
    cout << "4 é primo? " << (is_prime(4) ? "Sim" : "Não") << std::endl;
    cout << "5 é primo? " << (is_prime(5) ? "Sim" : "Não") << std::endl;
    cout << "6 é primo? " << (is_prime(6) ? "Sim" : "Não") << std::endl;
    cout << "7 é primo? " << (is_prime(7) ? "Sim" : "Não") << std::endl;

    return 0;
}
