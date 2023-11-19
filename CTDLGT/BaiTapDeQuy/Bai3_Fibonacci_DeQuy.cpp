#include <iostream>
using namespace std;

long long int Fibonacci(long long int n) {
    if (n <= 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    long long int n;
    cin >> n;
    cout << Fibonacci(n);
    return 0;
}