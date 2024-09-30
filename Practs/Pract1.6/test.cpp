#include <iostream>
using namespace std;

void convertToBinary(int n) {
    if (n > 1) {
        convertToBinary(n / 2); 
    }
    cout << n % 2; 
}

int main() {
    int decimal;
    cout << "Введіть десяткове число: ";
    cin >> decimal;

    cout << "Двійкове представлення: ";
    convertToBinary(decimal);
    cout << endl;

    return 0;
}