#include <stdio.h>
#define MAX 10
#define MIN 2
// prototype
void NhapMang(int a[], int &n);
void XuatMang(int a[], int n);
void XoaLe(int a[], int &n);
// ham main
int main()
{
    int a[MAX], n;
    printf("Nhap 1 mang bat ky: \n");
    NhapMang(a, n);
    printf("Mang vua nhap la: \n");
    XuatMang(a, n);
    XoaLe(a, n);
    printf("Mang sau khi xoa cac phan tu le la: \n");
    XuatMang(a, n);
    return 0;
}
void NhapMang(int a[], int &n)
{
    do
    {
        printf("Nhap so phan tu cho mang: \n");
        scanf("%d", &n);
    } while (!(MIN <= n && n <= MAX));
    for (int i = 0; i < n; i++)
    {
        printf("Nhap gia tri a[%d]: \n", i);
        scanf("%d", &a[i]);
    }
}
void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf('\n');
}
void XoaLe(int a[], int &n)
{
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 1)
        {
            int j = i;
            while (j != n)
            {
                a[j] = a[j+1];
                j++;
            }
            n--;
        }
}