#include <iostream>
using namespace std;

bool IsPerfectNumber(long long int number) {
    long long int sum = 1;
    for (long long int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            sum += i;
            if (i != number / i) {
                sum += number / i;
            }
        }
    }
    return sum == number;
}

int main() {
    long long int number;
    cin >> number;

    if (IsPerfectNumber(number)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
