#include <iostream>
using namespace std;

#define MAX 31

char map_array[MAX][MAX];
int n, m;

void InitializeArray()
{
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) 
            cin >> map_array[i][j];

    // Khoi tao linh canh (ngang)
    for (int i = 0; i <= m; i++)
    {
        map_array[0][i] = 'X';
        map_array[n][i] = 'X';
    }

    // Khoi tao linh canh (doc)
    for (int i = 0; i <= n; i++)
    {
        map_array[i][0] = 'X';
        map_array[i][m] = 'X';
    }
}

void OutputArray()
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++) 
            cout << map_array[i][j] << " ";
        cout << endl;
    }
}

void FindRoad(int x, int y, int count, int &min_count)
{
    if (map_array[x][y] == 'C')
    {
        min_count = min(min_count, count);
        cout << count;
        count = 0;
        return;
    }
    else if (map_array[x][y] == '.' || map_array[x][y] == 'B')
    {
        count++;
        map_array[x][y] = 'm';
        FindRoad(x, y + 1, count, min_count);
        FindRoad(x + 1, y, count, min_count);
        FindRoad(x, y - 1, count, min_count);
        FindRoad(x - 1, y, count, min_count);
    }
    OutputArray();
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m;

    n++;
    m++;

    InitializeArray();

    int b_x, b_y;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (map_array[i][j] == 'B')
            {
                b_x = i;
                b_y = j;
            }
        }

    int count = n * m;
    int max = 0;
    FindRoad(b_x, b_y, count, max);
    OutputArray();
    cout << max;

    return 0;
}