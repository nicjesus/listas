#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ifstream alturaFile("altura.txt");
    ifstream pesoFile("peso.txt");

    if (!alturaFile.is_open() || !pesoFile.is_open()) {
        cerr << "Erro ao abrir um dos arquivos de entrada." << endl;
        return 1;
    }

    string codigo;
    string codigoMaiorAltura, codigoMaiorPeso;
    double altura, peso;
    double maiorAltura = numeric_limits<double>::min();
    double maiorPeso = numeric_limits<double>::min();

    // Leitura do arquivo de alturas
    while (getline(alturaFile, codigo)) {
        alturaFile >> altura;
        alturaFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora a linha seguinte

        if (altura > maiorAltura) {
            maiorAltura = altura;
            codigoMaiorAltura = codigo;
        }
    }

    // Leitura do arquivo de pesos
    while (getline(pesoFile, codigo)) {
        pesoFile >> peso;
        pesoFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora a linha seguinte

        if (peso > maiorPeso) {
            maiorPeso = peso;
            codigoMaiorPeso = codigo;
        }
    }

    alturaFile.close();
    pesoFile.close();

    cout << "Pessoa com maior altura: " << codigoMaiorAltura << " com " << maiorAltura << " metros." << endl;
    cout << "Pessoa com maior peso: " << codigoMaiorPeso << " com " << maiorPeso << " kg." << endl;

    return 0;
}
