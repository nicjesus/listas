#include <iostream>
#include <cmath> 
using namespace std;

int main() {

    double cateto1, cateto2, hipotenusa;


    cout << "Digite o valor do primeiro cateto: ";
    cin >> cateto1;
    cout << "Digite o valor do segundo cateto: ";
    cin >> cateto2;

    hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);

    cout << "O valor da hipotenusa é: " << hipotenusa << endl;

    return 0;
}
