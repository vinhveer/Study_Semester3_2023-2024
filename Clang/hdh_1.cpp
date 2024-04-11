#include <stdio.h>
#include <stdlib.h>
struct ps
{
    int tdv; // thoi diem vao
    int tgcpu;
    int tgkt;
    int tgc;
    int trt;
};
typedef struct ps ps;
int cmp(const void *a, const void *b)
{
    ps *x = (ps *)a;
    ps *y = (ps *)b;
    return x->tdv - y->tdv;
}
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
        printf("Nhap thoi diem vao va thoi gian cpu cua P%d\n", i + 1);
        scanf("%d", &a[i].tdv);
        scanf("%d", &a[i].tgcpu);
    }
    qsort(a, n, sizeof(ps), cmp); // moi phan tu la 1 struct kieu ps
    // sap xep theo thoi diem vao r
    a[0].tgc = 0;
    a[0].tgkt = a[0].tdv + a[0].tgcpu;
    a[0].trt = a[0].tgkt - a[0].tdv;
    res1 = a[0].trt;
    //	 for(int i=1;i<=n-1;i++){
    // 	a[i].tgkt=a[i-1].tgkt+a[i].tgcpu;
    //	 }
    // tinh toan thoi gian ket thuc
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
    // sau buoc nay da tinh xong
    printf("Thoi gian cho trung binh va turnaroundtime cua tien trinh:%.2f %.2f", res / n, res1 / n);
}