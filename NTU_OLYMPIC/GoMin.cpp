#include <iostream>
using namespace std;

void InitializeArray(char array[][100], int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        // Khoi tao hang ngang (tren)
        array[i][0] = 'y';

        // Khoi tao hang ngang (duoi)
        array[i][m] = 'y'; // Change from i to m
    }

    for (int i = 0; i <= m; i++)
    {
        // Khoi tao hang doc (trai)
        array[0][i] = 'y';

        // Khoi tao hang doc (phai)
        array[n][i] = 'y';
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            array[i][j] = '0';
}

char CheckPosition(char array[][100], int y, int x)
{
    if (array[y][x] == 'x')
        return 'x';

    int count = 0;
    if (array[y - 1][x - 1] == 'x')
        count++;
    if (array[y - 1][x] == 'x')
        count++;
    if (array[y - 1][x + 1] == 'x')
        count++;
    if (array[y][x - 1] == 'x')
        count++;
    if (array[y][x + 1] == 'x')
        count++;
    if (array[y + 1][x - 1] == 'x')
        count++;
    if (array[y + 1][x] == 'x')
        count++;
    if (array[y + 1][x + 1] == 'x')
        count++;

    return static_cast<char>(count + '0'); 
}

void FillNumber(char array[][100], int n, int m)
{
    int k, x, y;
    cin >> k;
    for (int c = 0; c < k; c++)
    {
        cin >> y >> x;
        array[y][x] = 'x';
        array[y - 1][x - 1] = CheckPosition(array, y - 1, x - 1);
        array[y - 1][x] = CheckPosition(array, y - 1, x);
        array[y - 1][x + 1] = CheckPosition(array, y - 1, x + 1);
        array[y][x - 1] = CheckPosition(array, y, x - 1);
        array[y][x + 1] = CheckPosition(array, y, x + 1);
        array[y + 1][x - 1] = CheckPosition(array, y + 1, x - 1);
        array[y + 1][x] = CheckPosition(array, y + 1, x);
        array[y + 1][x + 1] = CheckPosition(array, y + 1, x + 1);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    char array[100][100];

    n++;
    m++;

    InitializeArray(array, n, m);

    FillNumber(array, n, m);

    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }

    return 0;
}