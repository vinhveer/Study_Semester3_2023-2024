#include <stdio.h>
#define MAX 10
#define MIN 2

void NhapMTV(int A[MAX][MAX], int &n)
{
    do
    {
        printf("Nhap vao thong tin MTV: \n");
        scanf("%d", &n);
    } while (!(MIN <= n && n <= MAX));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            printf("Nhap vao gia tri A[%d][%d]: \n", i, j);
            scanf("%d", &A[i][j]);
        }
}
void XuatMTV(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3d", A[i][j]);
        printf("\n");
    }
}
void TimMin(int A[MAX][MAX], int n, int &posi, int &posj, int &min)
{
    min = A[0][0];
    posi = 0; 
    posj = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (A[i][j] < min)
            {
                min = A[i][j];
                posi = i;
                posj = j;
            }
    }
}

int main()
{
    int A[MAX][MAX], n;
    int min;
    printf("Nhap vao MTV bat ky: \n");
    NhapMTV(A, n);
    printf("MTV vua nhap la: \n");
    XuatMTV(A, n);
    int posi, posj;
    TimMin(A, n, posi, posj, min);
    printf("Gia tri nho nhat trong MTV la:%d, tai vi tri x = %d, y = %d\n", min, posi, posj);
    return 0;
}


