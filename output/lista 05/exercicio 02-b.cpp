#include <iostream>
using namespace std;

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Numeros primos entre 2 e 1000:" << std::endl;
    for (int i = 2; i <= 1000; ++i) {
        if (is_prime(i)) {
            std::cout << i << " ";
        }
    }
    cout << std::endl;
    return 0;
}
