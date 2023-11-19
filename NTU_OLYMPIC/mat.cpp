#include <iostream>
#include <vector>
using namespace std;

void InputArray(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
}

void OutputArray(vector<vector<int>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void MulMatrix(vector<vector<int>> &matrix, vector<int> &save_value, int n, int k)
{
    int count = 0;
    while (count < k * n)
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp += matrix[(count / n)][j] * matrix[j][(count % n) + i]; // Adjust indices
            }
        }
        save_value.push_back(temp);
        count++;
    }
    for (int i = 0; i < save_value.size(); i++)
        cout << save_value[i] << " ";
    cout << endl;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int k, n, i, j, S;
    cin >> k >> n >> i >> j >> S;

    vector<vector<int>> matrix(n, vector<int>(n));
    vector<int> save_value;

    for (int index = 0; index < n; index++)
    {
        InputArray(matrix, n);
        OutputArray(matrix, n);
    }

    MulMatrix(matrix, save_value, n, k);

    return 0;
}
