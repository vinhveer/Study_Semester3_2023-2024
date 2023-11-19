#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int thickness = a;
    int count = 0;
    int index = 2;
    while (thickness < b) {
        thickness *= 2;
        count++;
    }
    if (thickness > b) {
        count--;
    }
    cout << count;
    return 0;
}