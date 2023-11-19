#include <iostream>
#include <vector>
using namespace std;

void printPascalTriangle(int n) {
    vector<vector<int>> triAngle(n);
    for (int i = 0; i < n; ++i) {
        triAngle[i].resize(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            triAngle[i][j] = triAngle[i - 1][j - 1] + triAngle[i - 1][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << triAngle[i][j];
            if (j < i) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    
    printPascalTriangle(n);

    return 0;
}