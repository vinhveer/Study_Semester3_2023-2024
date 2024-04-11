#include <stdio.h>
#include <stdlib.h>
struct ps
{
    float tdv; // thoi diem vao
    float tgcpu;
    float tgkt;
    float tgc;
    float trt;
};
typedef struct ps ps;
int main()
{
    int n;
    float res = 0, res1 = 0;
    printf("Nhap so luong tien trinh:");
    scanf("%d", &n);
    ps a[n];
    // n la so luong tien trinh
    // n la so luong tien trinh
    for (int i = 0; i < n; i++)
    {
        printf("P%d\n", i + 1);
        printf("tgv = ");
        scanf("%f", &a[i].tdv);
        printf("tgcpu = ");
        scanf("%f", &a[i].tgcpu);
    }
    //	 qsort(a,n,sizeof(ps),cmp);// moi phan tu la 1 struct kieu ps
    // sap xep theo thoi diem vao r
    a[0].tgc = 0;
    a[0].tgkt = a[0].tdv + a[0].tgcpu;
    a[0].trt = a[0].tgkt - a[0].tdv;
    res1 = a[0].trt;

    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i].tdv > a[i - 1].tgkt)
        {
            // neu tdv cua thang sau nho hon thoi diem vao cua thang truoc thi
            a[i].tgc = 0; // thoi gian cho cua no bang 0
            a[i].tgkt = a[i].tdv + a[i].tgcpu;
            res += a[i].tgc;
            a[i].trt = a[i].tgkt - a[i].tdv;
            res1 += a[i].trt;
        }
        else
        {
            a[i].tgc = a[i - 1].tgkt - a[i].tdv;
            a[i].tgkt = a[i - 1].tgkt + a[i].tgcpu;
            res += a[i].tgc;
            a[i].trt = a[i].tgkt - a[i].tdv;
            res1 += a[i].trt;
        }
    }
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i <= n - 1; i++)
    {
        printf("\nP[%d]\t\t%.2f\t\t%.2f\t\t%.2f", i + 1, a[i].tgcpu, a[i].tgc, a[i].trt);
    }
    // sau buoc nay da tinh xong
    printf("\n\nAverage Waiting Time:%.2f", res / n);
    printf("\nAverage Turnaround Time:%.2f", res1 / n);
}