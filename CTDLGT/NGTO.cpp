#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(unsigned long long int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    
    for (long long int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    } 
    
    return true;
}

int main() {
    long long int n;
    scanf("%lld", &n);

    if (isPrime(n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}