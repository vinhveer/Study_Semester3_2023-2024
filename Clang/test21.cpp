#include <stdio.h>

void Max(int a[], int n,)
int main()
{
    int n, m, x, d, c;
    printf("Nhap so hang n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);
    int a[n][m];
    printf("Nhap ma tran %dx%d:\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Ma tran %dx%d vua nhap:\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Nhap gia tri x can tim: ");
    scanf("%d", &x);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == x)
            {
                printf("Gia tri %d xuat hien tai vi tri [%d][%d]\n", x, i, j);
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    if (flag == 0)
    {
        printf("Khong tim thay gia tri %d trong ma tran\n", x);
    }
    printf("Nhap dong d can kiem tra: ");
    scanf("%d", &d);
    int check = 1;
    for (int i = 0; i < m - 1; i++)
    {
        if (a[d][i] > a[d][i + 1])
        {
            check = 0;
            break;
        }
    }
    if (check == 1)
    {
        printf("Dong %d da duoc sap xep theo thu tu tang dan\n", d);
    }
    else
    {
        printf("Dong %d chua duoc sap xep theo thu tu tang dan\n", d);
    }
    printf("Nhap cot c can tim gia tri nho nhat va tinh trung binh cong: ");
    scanf("%d", &c);
    int min = a[0][c];
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i][c] < min)
        {
            min = a[i][c];
        }
        sum += a[i][c];
    }
    printf("Gia tri nho nhat tren cot %d la %d\n", c, min);
    printf("Trung binh cong cua cac phan tu tren cot %d la %.2f\n", c, sum / n);
    return 0;
}
