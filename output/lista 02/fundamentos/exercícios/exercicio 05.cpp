#include <iostream>
using namespace std;

int main() {
    
    double largura, comprimento, area;

    
    cout << "Insira a largura da sala (em metros): ";
    cin >> largura;

   
    cout << "Insira o comprimento da sala (em metros): ";
    cin >> comprimento;

   
    area = largura * comprimento;

    
    cout << "A area da sala é: " << area << " metros quadrados." << endl;

    return 0;
}
