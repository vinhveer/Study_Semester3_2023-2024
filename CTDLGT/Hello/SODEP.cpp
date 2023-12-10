#include <iostream>
using namespace std;

int main() {
    long long int number, sum = 0;
    cin >> number;

    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    
    if (sum % 10 == 9) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}