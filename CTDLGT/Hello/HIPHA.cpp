#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    int temp;
    int distance = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 1)
            distance++;
        else
            distance--;
    }
    cout << abs(distance);
    return 0;
}