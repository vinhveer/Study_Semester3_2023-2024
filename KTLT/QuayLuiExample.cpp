#include <stdio.h>
#define N 30

int x[N]; // Lưu các thành phần nghiệm
int k;    // k số nhị phân

// In bộ nghiệm ra màn hình
void Print()
{
    for (int j = 0; j < k; j++)
        printf("%d", x[j]);
    printf("\n");
}

// Quay lui
void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == k)
            Print();
        else
            Try(i + 1);
    }
}

int main()
{
    k = 3;
    Try(0);
    return 0;
}