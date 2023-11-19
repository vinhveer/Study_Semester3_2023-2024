#include <stdio.h>
#include <stdbool.h>

bool IsPalindrome(long long int num) {
    long long int original_num = num;
    long long int reverse_num = 0;
    long long int remainder = 0;

    while (num > 0) {
        remainder = num % 10;
        reverse_num = reverse_num * 10 + remainder;
        num = num / 10;
    }

    return reverse_num == original_num;
}

int main() {
    int count;
    long long int array_num[1000];

    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%lld", &array_num[i]);
    }

    for (int i = 0; i < count; i++) {
        if (IsPalindrome(array_num[i])) {
            printf("%d ", array_num[i]);
        }
    }

    return 0;
}
