#include <iostream>
#define N 20

int a[] = {0, 3, 5, 6, 10};
int n = sizeof(a) / sizeof(a[0]);
int s = 9;
int L[N][N];

void Init()
{
    for (int i = 0; i <= n; i++)
    {
        L[0][i] = 0;
        L[i][0] = 1;
    }
    L[0][0] = 1;
}

void Dynamic()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (L[i - 1][j] == 1 || (j >= a[i] && L[i - 1][j - a[i]] == 1))
            {
                L[i][j] = 1;
            }
        }
    }
}

void Print()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            printf("%5d", L[i][j]);
        }
        printf("\n");
    }
}

void Track()
{
    if (L[n][s] == 1)
    {
        for (int i = n; i > 0; i--)
        {
            if (L[i][s] == 1 && L[i - 1][s] == 0)
            {
                printf("%d ", a[i]);
                s -= a[i];
            }
        }
        printf("\n");
    }
}

int main()
{
    Init();
    Dynamic();
    Print();
    Track();

    return 0;
}
