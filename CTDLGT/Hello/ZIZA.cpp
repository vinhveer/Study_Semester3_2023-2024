#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[50][50] = {0};
    int row = 0, col = 0;
    int direction = 1;

    // Điền ma trận theo định dạng zigzag
    for (int num = 1; num <= n * n; num++) {
        matrix[row][col] = num;
        if (direction == 1) {
            if (row - 1 >= 0 && col + 1 < n) {
                row--;
                col++;
            } else {
                direction = -1;
                if (col + 1 < n) {
                    col++;
                } else {
                    row++;
                }
            }
        } else {
            if (col - 1 >= 0 && row + 1 < n) {
                row++;
                col--;
            } else {
                direction = 1;
                if (row + 1 < n) {
                    row++;
                } else {
                    col++;
                }
            }
        }
    }

    // In ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}