#include <iostream>
using namespace std;

int main() {
    cout << "Triplos pitagóricos:\n";

    for (int lado1 = 1; lado1 <= 20; ++lado1) {
        for (int lado2 = 1; lado2 <= 20; ++lado2) {
            for (int hipotenusa = 1; hipotenusa <= 20; ++hipotenusa) {
                // Verifica se é um triplo pitagórico
                if (lado1 * lado1 + lado2 * lado2 == hipotenusa * hipotenusa) {
                    cout << "Lados: " << lado1 << ", " << lado2 << ", Hipotenusa: " << hipotenusa << endl;
                }
            }
        }
    }

    return 0;
}
