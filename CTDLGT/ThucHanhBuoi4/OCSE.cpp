#include <iostream>
using namespace std;

const int MAX_SIZE = 101;

int n, m, y, x;
int garden[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

int CanMove(int i, int j)
{
    return (i >= 1 && i <= n && j >= 1 && j <= m && garden[i][j] == 0 && visited[i][j] == 0);
}

void dfs(int i, int j, int &count)
{
    visited[i][j] = 1;
    count++;

    if (CanMove(i - 1, j))
        dfs(i - 1, j, count);
    if (CanMove(i + 1, j))
        dfs(i + 1, j, count);
    if (CanMove(i, j - 1))
        dfs(i, j - 1, count);
    if (CanMove(i, j + 1))
        dfs(i, j + 1, count);
}

int main()
{
    cin >> n >> m >> y >> x;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> garden[i][j];

    int count = 0;
    dfs(y, x, count);

    cout << count;

    return 0;
}
