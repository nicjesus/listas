#include <iostream>
using namespace std;

int main() {
    //o usuário irá ver digitar os valores de todos os lados do triangulo.
    float lado1, lado2, lado3;
    cout << "Digite a medida do primeiro lado do triangulo:" << endl;
    cin >> lado1;
    cout << "Digite a medida do segundo lado do triangulo:" << endl;
    cin >> lado2;
    cout << "Digite a medida do terceiro lado do triangulo:" << endl;
    cin >> lado3;
//obs: Abaixo também pode ser usado o switch case, mas preferi a função if.
    if(lado1 == lado2 && lado1 == lado3){
        cout << "O seu triangulo e equilatero" << endl;   
    }
    else if(lado1 == lado2 || lado1 == lado3 || lado2 == lado3){
        cout << "O seu triangulo e isoscele." << endl;
    }else{
        cout << "O seu triangulo e escaleno." << endl;
    }

    return 0;
    system("pause");
}