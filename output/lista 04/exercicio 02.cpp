#include <iostream>
using namespace std;

int main() {
    // Primeiro padrão
    cout << "Primeiro padrão:" << endl;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        cout << '\n';
    }

    // Segundo padrão
    cout << "\nSegundo padrão:" << endl;
    for (int i = 5; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        cout << '\n';
    }

    // Terceiro padrão
    cout << "\nTerceiro padrão:" << endl;
    for (int i = 1; i <= 5; ++i) {
        for (int k = 5 - i; k > 0; --k) {
            cout << "  "; // Adiciona espaços
        }
        for (int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        cout << '\n';
    }

    // Quarto padrão
    cout << "\nQuarto padrão:" << endl;
    for (int i = 5; i >= 1; --i) {
        for (int k = 5 - i; k > 0; --k) {
            cout << "  "; // Adiciona espaços
        }
        for (int j = 1; j <= i; ++j) {
            cout << "* ";
        }
        cout << '\n';
    }

    return 0;
}
