#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;
int n, sx, sy, dx, dy;

bool isValid(int x, int y) 
{
    return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y]);
}

bool dfs(int x, int y) 
{
    if (x == dx && y == dy) return true;
    
    visited[x][y] = true;
    
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < 4; i++) 
    {
        int newX = x + direction[i][0];
        int newY = y + direction[i][1];

        if (isValid(newX, newY)) 
        {
            if (dfs(newX, newY)) 
            {
                return true;
            }
        }
    }
    
    return false;
}

int main() 
{
    cin >> n >> sx >> sy >> dx >> dy;
    sx--; sy--; dx--; dy--;

    grid.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> grid[i][j];
        }
    }

    if (dfs(sx, sy)) 
    {
        cout << "YES" << endl;
    } 
    else 
    {
        cout << "NO" << endl;
    }

    return 0;
}


/*
3 1 1 3 3
1 0 1
1 0 0
1 1 0
*/
