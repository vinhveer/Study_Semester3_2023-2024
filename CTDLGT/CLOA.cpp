#include <stdio.h>

int main() {
    int matrix[50][50];
    int n;
    scanf("%d", &n);
    int number = 1; // Bắt đầu từ số 1
    int row = 0, col = 0;

    for (int layer = 0; layer < (n + 1) / 2; layer++) {
        // Đi xuống
        for (int i = col; i < n - col; i++) {
            matrix[row][i] = number++;
        }
        // Đi sang phải
        for (int i = row + 1; i < n - row; i++) {
            matrix[i][n - 1 - col] = number++;
        }
        // Đi lên
        for (int i = n - 2 - col; i >= col; i--) {
            matrix[n - 1 - row][i] = number++;
        }
        // Đi sang trái
        for (int i = n - 2 - row; i > row; i--) {
            matrix[i][col] = number++;
        }
        row++;
        col++;
    }

    // In ra ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
