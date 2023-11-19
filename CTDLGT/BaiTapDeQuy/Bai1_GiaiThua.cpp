#include <iostream>
using namespace std;

long long int Factorical(long long int n) {
    if (n == 1)
        return 1;
    return n * Factorical(n - 1);
}

int main() {
    long long int n;
    cin >> n;
    cout << Factorical(n);
    return 0;
}