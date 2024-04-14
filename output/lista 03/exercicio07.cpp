#include <iostream>
using namespace std;

int main() {
    int senha;
//o usuário irá digitar a senha e constatará se está permitido ou com acesso negado.
    cout << "Digite a senha: ";
    cin >> senha;

    if (senha == 1234) {
        cout << "ACESSO PERMITIDO" << endl;
    } else {
        cout << "ACESSO NEGADO" << endl;
    }

    return 0;
}
