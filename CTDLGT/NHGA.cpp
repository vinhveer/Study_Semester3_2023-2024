#include <stdio.h>
#include <stdlib.h>

// Hàm so sánh để sắp xếp mảng
int compare(const void *a, const void *b) {
    return (*(long long int *)a - *(long long int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    long long int addresses[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &addresses[i]);
    }

    // Sắp xếp mảng địa chỉ
    qsort(addresses, n, sizeof(long long int), compare);

    // Tìm khoảng cách nhỏ nhất giữa hai căn nhà liền kề
    long long int min_distance = addresses[1] - addresses[0];
    for (int i = 2; i < n; i++) {
        long long int distance = addresses[i] - addresses[i - 1];
        if (distance < min_distance) {
            min_distance = distance;
        }
    }

    printf("%lld\n", min_distance);

    return 0;
}
