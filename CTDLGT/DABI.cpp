#include <stdio.h>

int CheckSpecialNumber(long long int number) {
    long long int number_check = number;
    long long int sum_element_num = 0;
    while (number_check != 0) {
        sum_element_num += number_check % 10;
        number_check /= 10;
    }
    if (number % sum_element_num == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    long long int number;
    scanf("%lld", &number);
    printf("%d", CheckSpecialNumber(number));
    return 0;
}