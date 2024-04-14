#include <iostream>
using namespace std;

int main() {
//variável para fazer os testes no switch case
    char caractere;
    
    cout << "Digite um caractere: ";
    cin >> caractere;
    
    switch(tolower(caractere)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << caractere << " e uma vogal." << endl;
            break;
        default:
            cout << caractere << " Nao e uma vogal." << endl;
    }
    
    return 0;
}
