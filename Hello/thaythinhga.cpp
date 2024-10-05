#include <stdio.h>

void ReadFile(int a[], int &n)
{
    FILE *f = fopen("input.txt", "r");

    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &a[i]);

    fclose(f);
}

void Print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int main()
{
    int a[100], n;
    ReadFile(a, n);
    Print(a, n);
    return 0;
}
