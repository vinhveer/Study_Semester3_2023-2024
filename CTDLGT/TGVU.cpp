#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int start = n / 2;
    int end = start;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= start && j <= end)
                cout << "D";
            else
                cout << "*";
        }
        if (i < n / 2) {
            start--;
            end++;
        }
        else {
            start++;
            end--;
        }
        cout << endl;
    }
    return 0;
}
