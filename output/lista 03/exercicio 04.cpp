#include <iostream>
#include <cmath>
using namespace std;

int binarioParaDecimal(int numeroBinario) {
    int numeroDecimal = 0;
    int expoente = 0;
    
    // Convertendo o número binário para decimal
    while (numeroBinario != 0) {
        int digito = numeroBinario % 10;
        numeroDecimal += digito * pow(2, expoente);
        numeroBinario /= 10;
        expoente++;
    }
    
    return numeroDecimal;
}

int main() {
    int numeroBinario;
    
    cout << "Digite um número binário (apenas zero e uns): ";
    cin >> numeroBinario;
    
    int numeroDecimal = binarioParaDecimal(numeroBinario);
    
    cout << "O valor decimal correspondente é: " << numeroDecimal << endl;
    
    return 0;
}
