#include <iostream>
using namespace std;

bool is_perfect(int number) {
    int sum = 1;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            sum += i;
            if (i * i != number) {
                sum += number / i;
            }
        }
    }
    return sum == number;
}

void print_factors(int number) {
    cout << "Fatores de " << number << ": 1";
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            cout << ", " << i;
            if (i * i != number) {
                cout << ", " << number / i;
            }
        }
    }
    cout << endl;
}

int main() {
    cout << "Numeros perfeitos entre 1 e 1000:" << std::endl;
    for (int i = 1; i <= 1000; ++i) {
        if (is_perfect(i)) {
            cout << i << " é um número perfeito." << std::endl;
            print_factors(i);
        }
    }
    return 0;
}
