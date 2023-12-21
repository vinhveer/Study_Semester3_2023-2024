#include <stdio.h>
#define MAX 50

int x[MAX]; // lưu nghiệm
int k, n;

// khởi tạo
void khoiTao()
{
    for (int i = 0; i <= n; i++)
        x[i] = 0;
}

// xuất nghiệm
void xuatNghiem()
{
    for (int i = 1; i <= k; i++)
        printf("%d ", x[i]);
    printf("\n");
}

void Try(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if (i == k)
            xuatNghiem();
        else
            Try(i + 1);
    }
}

int main()
{
    x[0] = 0;
    printf("Nhap k, n: ");
    scanf("%d%d", &k, &n);
    khoiTao();
    Try(1);
    return 0;
}
