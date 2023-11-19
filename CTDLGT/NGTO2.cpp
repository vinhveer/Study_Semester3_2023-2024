#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n) {
    bool prime[n+1];
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    
    printf("Các số nguyên tố trong khoảng từ 2 đến %d là:\n", n);
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n < 2) {
        printf("Không có số nguyên tố nào trong khoảng này.\n");
    } else {
        sieveOfEratosthenes(n);
    }
    
    return 0;
}
