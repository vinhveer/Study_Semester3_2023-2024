#include <iostream>
using namespace std;

int main() {
    long long int n, m;
    cin >> n >> m;

    // Tính số lượng chó (c)
    long long int c = (m - 2 * n) / 2;

    // Tính số lượng gà (g)
    long long int g = n - c;

    // Kiểm tra nếu c và g đều là số không âm và thỏa mãn điều kiện
    if (c >= 0 && g >= 0 && 2 * g + 4 * c == m) {
        cout << g << " " << c;
    } else {
        cout << -1; // Không có đáp án
    }

    return 0;
}
