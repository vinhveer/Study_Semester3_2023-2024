#include <iostream>
using namespace std;

string CheckSquare(int x[], int y[], int sum_x, int sum_y) {
    int count = 0;
    int distance = 0;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
      {
        
      }
        
    else if (sum_x == sum_y)
        return "YES";
    else
        return "NO";
}

int main() {
    int x[4];
    int y[4];
    int sum_x = 0;
    int sum_y = 0;

    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
        sum_x += x[i];
        sum_y += y[i];
    }

    cout << CheckSquare(x, y, sum_x, sum_y);

    return 0;
}