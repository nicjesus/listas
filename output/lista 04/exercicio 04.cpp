#include <iostream>
using namespace std;

int main() {
    // Definição dos preços de varejo dos produtos
    const double preco_produto1 = 2.98;
    const double preco_produto2 = 4.50;
    const double preco_produto3 = 9.98;
    const double preco_produto4 = 4.49;
    const double preco_produto5 = 6.87;

    int numero_produto;
    int quantidade;
    double total_venda = 0;

    // Loop para ler pares de números até que o usuário decida parar
    while (true) {
        cout << "Digite o número do produto (1-5, ou 0 para sair): ";
        cin >> numero_produto;

        // Verifica se o usuário deseja sair
        if (numero_produto == 0) {
            break;
        }

        cout << "Digite a quantidade vendida: ";
        cin >> quantidade;

        // Calcula o valor da venda para o produto selecionado
        switch (numero_produto) {
            case 1:
                total_venda += preco_produto1 * quantidade;
                break;
            case 2:
                total_venda += preco_produto2 * quantidade;
                break;
            case 3:
                total_venda += preco_produto3 * quantidade;
                break;
            case 4:
                total_venda += preco_produto4 * quantidade;
                break;
            case 5:
                total_venda += preco_produto5 * quantidade;
                break;
            default:
                cout << "Número de produto inválido. Por favor, digite um número de 1 a 5." << endl;
                break;
        }
    }

    // Exibe o total de vendas
    cout << "O total de vendas é: R$ " << total_venda << endl;

    return 0;
}
