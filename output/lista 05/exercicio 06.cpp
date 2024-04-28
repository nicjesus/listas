#include <iostream>
using namespace std;


// Função recursiva para resolver as Torres de Hanói
void torres_de_hanoi(int discos, int estaca_origem, int estaca_destino, int estaca_temporaria) {
    if (discos == 1) {
        cout << "Mova o disco 1 da estaca " << estaca_origem << " para a estaca " << estaca_destino << std::endl;
        return;
    }

    torres_de_hanoi(discos - 1, estaca_origem, estaca_temporaria, estaca_destino);
    cout << "Mova o disco " << discos << " da estaca " << estaca_origem << " para a estaca " << estaca_destino << std::endl;
    torres_de_hanoi(discos - 1, estaca_temporaria, estaca_destino, estaca_origem);
}

int main() {
    int discos;
    cout << "Digite o número de discos: ";
    cin >> discos;

    torres_de_hanoi(discos, 1, 3, 2); // Inicia com estaca_origem = 1, estaca_destino = 3 e estaca_temporaria = 2

    return 0;
}
