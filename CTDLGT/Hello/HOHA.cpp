#include <iostream>
using namespace std;

int main() {
    long long int number, sum = 0;
    cin >> number;
    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }

    cout << sum;

    if (sum == number) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}