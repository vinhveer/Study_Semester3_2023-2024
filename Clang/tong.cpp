#include <stdio.h>
#include <math.h>
#define MAX 10000

void Input(int &n, int a[])
{
    printf("N = ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void Output(int n, int a[])
{
    for (int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
void SumRange(int n, int a[])
{
    int x,y;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        a[i] = sum;
    }
}
int main()
{
    int n, a[MAX];
    Input(n, a);
    Output(n, a);
    SumRange(n, a);
    Output(n, a);
}