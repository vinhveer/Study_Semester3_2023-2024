#include <iostream>
using namespace std;

void Character(int x, int y, char a[][100]) {
    if (a[x][y] == 'x')
        cout << "Ti wins";
    else if (a[x][y] == 'o')
        cout << "Teo wins";
}

int Check(char a[][100], int n) {
    // Check horizontally, vertically, and diagonally
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            char current = a[x][y];
            if (current == '.')
                continue;

            // Check horizontally
            int count = 0;
            for (int j = y; j < n && a[x][j] == current; j++) {
                count++;
            }
            if (count >= 5) {
                Character(x, y, a);
                return 1;
            }

            // Check vertically
            count = 0;
            for (int i = x; i < n && a[i][y] == current; i++) {
                count++;
            }
            if (count >= 5) {
                Character(x, y, a);
                return 1;
            }

            // Check diagonally (right-down)
            count = 0;
            for (int i = x, j = y; i < n && j < n && a[i][j] == current; i++, j++) {
                count++;
            }
            if (count >= 5) {
                Character(x, y, a);
                return 1;
            }

            // Check diagonally (left-down)
            count = 0;
            for (int i = x, j = y; i < n && j >= 0 && a[i][j] == current; i++, j--) {
                count++;
            }
            if (count >= 5) {
                Character(x, y, a);
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int n;
    cin >> n;
    char a[100][100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    if (Check(a, n) == 0) {
        cout << "Not yet";
    }

    return 0;
}