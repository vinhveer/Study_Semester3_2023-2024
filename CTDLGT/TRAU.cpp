#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int a, b, c;
    a = 0;
    b = 0;
    c = 0;

    while (true) {
        // Tăng số trâu đứng
        a++;
        b = (m - 5 * a) / 3;
        c = n - a - b;

        // Kiểm tra xem có đủ cỏ hay không
        if (5 * a + 3 * b == m) {
            printf("%d %d %d\n", a, b, c);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}
