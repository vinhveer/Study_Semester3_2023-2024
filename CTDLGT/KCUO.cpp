#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int half_count = (n - 1) / 2 + 1;

    int x = half_count - 1;
    int y = half_count;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < x || j >= y) {
                cout << "*";
            } else {
                cout << "D";
            }
        }
        cout << endl;
        if (i < half_count - 1) {
            x--;
            y++;
        } else {
            x++;
            y--;
        }
    }
    return 0;
}