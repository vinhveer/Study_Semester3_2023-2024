#include <iostream>
using namespace std;

long long int Fibonacci(long long int n) {
    long long int a[1000];
    long long int fibonacci = 0;
    a[0] = 1;
    a[1] = 1;
    for (int i = 2;i < n; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n - 1];
}

int main() {
    long long int n;
    cin >> n;
    cout << Fibonacci(n);
    return 0;
}
