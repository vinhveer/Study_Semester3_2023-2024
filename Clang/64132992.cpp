// Nguyen The Vinh - 64132992
#include<stdio.h>
#define MAX 100

void Nhap(int a[], int &n)
{
    printf("Nhap n:");
    do
    {
        scanf("%d", &n);
    } while (!(5 <= n && n <= 100));
    for (int i = 0; i <= n - 1; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }
}

void Xuat(int a[], int n)
{
    for (int i = 0; i <= n - 1; i++)
        printf(" %d", a[i]);
}

int Snt(int a)
{
    for (int i = 2; i < a; i++)
        if (a % i == 0)
            return 0;
    return 1;
}

void InSnt(int a[], int n)
{
    for (int i = 0; i <= n - 1; i++)
        if (a[i] / 10 != 0 && Snt(a[i]))
            printf("%d ", a[i]);
}

int ChiaHet(int a[], int n)
{
    int cou= 0;
    for (int i = 0; i <= n - 1; i++)
        if (a[i] % 2 == 0 && a[i] % 3 == 0)
            cou++;
    return cou;
}

void TachSnt(int a[], int snt[], int b[], int n, int &m, int &x)
{
    m= x= 0;
    for (int i = 0; i <= n - 1; i++)
        if (Snt(a[i]))
        {
            snt[m++]= a[i];
        }
        else
        {
            b[x++]= a[i];
        }
}

int main()
{
    int a[MAX], snt[MAX], b[MAX];
    int n, m, x;
    Nhap(a, n);
    printf("Mang vua nhap la:");
    Xuat(a, n);
    printf("\nCac phan tu co 2 chu so va la snt:");
    InSnt(a, n);
    printf("\nCo %d phan tu chia het cho 2 va 3", ChiaHet(a, n));
    TachSnt(a, snt, b, n ,m ,x);
    printf("\nMang chua cac phan tu snt gom: ");
    Xuat(snt, m);
    printf("\nMang chua cac phan tu con lai gom: ");
    Xuat(b, x);
    return 0;
}