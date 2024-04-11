#include <stdio.h>

struct HinhChuNhat
{
    float chieuDai;
    float chieuRong;
};

float TinhDienTichHinhChuNhat(struct HinhChuNhat hcn)
{
    return hcn.chieuDai * hcn.chieuRong;
}

float TinhChuViHinhChuNhat(struct HinhChuNhat hcn)
{
    return (hcn.chieuDai + hcn.chieuRong) * 2;
}

void XuatHinhChuNhat(struct HinhChuNhat hcn)
{
    printf("Hinh chu nhat co chieu dai la %.2f, chieu rong la %.2f\n", hcn.chieuDai, hcn.chieuRong);
    printf("Dien tich la %.2f\n", TinhDienTichHinhChuNhat(hcn));
    printf("Chu vi la %.2f\n", TinhChuViHinhChuNhat(hcn));

    // Xuất hình chữ nhật
    int i, j;
    for (i = 1; i <= hcn.chieuRong; i++)
    {
        for (j = 1; j <= hcn.chieuDai; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    struct HinhChuNhat hcn;
    printf("Nhap chieu dai: ");
    scanf("%f", &hcn.chieuDai);
    printf("Nhap chieu rong: ");
    scanf("%f", &hcn.chieuRong);

    XuatHinhChuNhat(hcn);

    return 0;
}
