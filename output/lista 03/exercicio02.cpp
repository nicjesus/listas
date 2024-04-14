#include <iostream>
using namespace std;
 
int main(){
    
double etanolpreco, gasolinapreco;
double conta = etanolpreco / gasolinapreco;

cout << "Digite o preço do litro de etanol: ";
cin >> etanolpreco;
cout << "Digite o preço do litro de gasolina: ";
cin >> gasolinapreco;

if (conta < 0.7) {
    cout << "Recomenda-se abastecer com etanol." << endl;
    } else {
        cout << "Recomenda-se abastecer com gasolina." << endl;
    }
}
