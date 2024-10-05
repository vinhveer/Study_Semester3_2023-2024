#include <iostream>
#include <vector>

using namespace std;

// Declare maps
int n;
vector<vector<int>> grid;
vector<vector<bool>> visited;

// Declare position
int sx, sy, dx, dy;

// Declare result structure
struct result {
    int x;
    int y;
};
vector<result> results;

// Check if a cell is valid for traversal
bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && !visited[x][y]);
}

// Depth-First Search (DFS) to find path
bool dfs(int x, int y) {
    // Mark this cell as visited
    visited[x][y] = true;

    // If we reach the destination cell, return true
    if (x == dx && y == dy) {
        results.push_back({x, y}); // Add destination to results
        return true;
    }

    // Define possible movements (down, up, right, left)
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Explore all possible directions
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (isValid(newX, newY)) {
            if (dfs(newX, newY)) {
                results.push_back({x, y}); // Add this cell to the result path
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Input map size and positions
    cin >> n >> sx >> sy >> dx >> dy;
    sx--; sy--; dx--; dy--; // Adjust for 0-based indexing

    // Resize vectors
    grid.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    // Enter matrix values
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    // Check if path is found
    if (dfs(sx, sy)) {
        cout << results.size() << endl; // Output the number of steps (path length)
        for (const auto &row : results)
            cout << row.x + 1 << " " << row.y + 1 << endl; // Convert back to 1-based indexing for output
    } else {
        cout << "No path found.\n";
    }

    return 0;
}

