#include <stdio.h>

#define Mul(x, y) x * y

int main()
{
    int a = 3;
    int b = 2;

    int ketqua = Mul(a + 1, b + 2);

    printf("Ket qua: %d\n", ketqua);

    return 0;
}
