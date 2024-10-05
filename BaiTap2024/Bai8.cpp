#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> transposed(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    vector<vector<int>> transposed = transpose(matrix);
    cout << "Ma tr?n dã chuy?n v?:" << endl;
    for (const auto& row : transposed) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

