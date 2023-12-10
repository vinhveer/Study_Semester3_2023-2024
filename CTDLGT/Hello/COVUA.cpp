#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    cout << "W";
                } else {
                    cout << "B";
                }
            } else {
                if (j % 2 == 0) {
                    cout << "B";
                } else {
                    cout << "W";
                }
            }
        }
        cout << endl;
    }
}