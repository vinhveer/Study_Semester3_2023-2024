#include <stdio.h>

#define MAX 50

void DocFile(int &n, int a[])
{
    FILE *fp = fopen("input.txt", "r+");
    if (fp == NULL)
        printf("File khong ton tai!");

    fscanf(fp, "%d", &n);
    if (n < 8 || n > 50)
    {
        printf("Khong nam trong gioi han!");
        return;
    }

    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);

    fclose(fp);
}

void GhiFile(int n, int a[])
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            dem++;

    FILE *fp = fopen("output.txt", "w+");
    if (fp == NULL)
        printf("File khong ton tai");

    fprintf(fp, "So luong: %d\n", dem);

    fclose(fp);
}

int main()
{
    int n;
    int a[MAX];

    DocFile(n, a);
    GhiFile(n, a);

    return 0;
}