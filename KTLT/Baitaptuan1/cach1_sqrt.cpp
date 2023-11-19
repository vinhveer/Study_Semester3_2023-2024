#include <stdio.h>
#include <math.h>

// Determine the primality of a given number (use sqrt() function in math.h)
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

int main()
{
    int number;
    printf("Nhap mot so bat ky: ");
    scanf("%d", &number);

    if (isPrime(number))
        printf("%d la so nguyen to!\n", number);
    else
        printf("%d khong phai la so nguyen to!\n", number);

    return 0;
}
