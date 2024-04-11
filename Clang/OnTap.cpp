#include <stdio.h>
#include <math.h>
#define MAX 20

void Input(int a[MAX][MAX], int &m, int &n)
{
    printf("Nhap kich thuoc ma tran (nxm): \n");
    do
    {
        printf("n = ");
        scanf("%d", &n);
    } while (n < 2 || n > 20);
    do
    {
        printf("m = ");
        scanf("%d", &m);
    } while (m < 2 || m > 20);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
}

void Output(int a[MAX][MAX], int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int MaxBorder(int a[MAX][MAX], int m, int n)
{
    int max = a[0][0];
    for (int i = 0; i < n; i++)
    {
        if (a[0][i] > max)
            max = a[0][i];
        if (a[n - 1][i] > max)
            max = a[n - 1][i];
    }
    for (int i = 0; i < m; i++)
    {
        if (a[i][0] > max)
            max = a[i][0];
        if (a[i][m - 1] > max)
            max = a[i][m - 1];
    }
    return max;
}


int SumColumn(int a[MAX][MAX], int n, int c)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i][c];
    return sum;
}

int MaxSquareNum(int a[MAX][MAX], int m, int n)
{
    int maxsq = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (sqrt(a[i][j]) == (int)sqrt(a[i][j]) && a[i][j] > maxsq)
                maxsq = a[i][j];
    return maxsq;
}

int main()
{
    int a[MAX][MAX];
    int n, m;
    Input(a, m, n);
    Output(a, m, n);
    printf("Max Border is: %d\n", MaxBorder(a, m, n));
    int c;
    printf("c = ");
    scanf("%d", &c);
    printf("Sum column is: %d\n", SumColumn(a, n, c));
    printf("Max square number is: %d\n", MaxSquareNum(a, m, n));
}