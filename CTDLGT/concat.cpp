#include <stdio.h>

// Hàm đệ quy tính tổng giai thừa từ 1 đến n
int tinhTongGiaiThua(int n, int *tong) {
    if (n == 0) return 1;  // Trường hợp cơ bản, giai thừa của 0 là 1

    // Tính giai thừa của n
    int giaiThua = n * tinhTongGiaiThua(n - 1, tong);

    // Cộng giai thừa của n vào tổng
    *tong += giaiThua;

    return giaiThua;  // Trả về giai thừa của n để tính tiếp các bước đệ quy
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    // Kiểm tra trường hợp n <= 0
    if (n <= 0) {
        printf("Vui long nhap mot so lon hon 0.\n");
        return 1;  // Kết thúc chương trình với mã lỗi
    }

    int tong = 0;  // Biến để lưu tổng giai thừa
    tinhTongGiaiThua(n, &tong);

    printf("Tong giai thua tu 1 den %d la: %d\n", n, tong);
    return 0;
}
