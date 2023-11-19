#include <iostream>
using namespace std;

int main() {
    long long int number;
    long long int divine = 2;
    cin >> number;
    while (number != 1) {
        if (number % divine == 0) {
            cout << divine;
            number /= divine;
            if (number != 1)
                cout << "*";
        } else {
            divine++;
        } 
    }
    return 0;
}