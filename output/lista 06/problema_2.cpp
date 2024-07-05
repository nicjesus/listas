#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//inicia a função main
int main() {
    string filename = "mochileiro.txt";
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        return 1;
    }

    char targetChar;
    cout << "Informe o caractere a ser contado: ";
    cin >> targetChar;

    string line;
    int lineNumber = 1;

    while (getline(inputFile, line)) {
        int count = 0;
        for (char c : line) {
            if (c == targetChar) {
                count++;
            }
        }
        cout << "Linha " << lineNumber << ": " << count << " ocorrências de '" << targetChar << "'" << endl;
        lineNumber++;
    }

    inputFile.close();
    return 0;
}
