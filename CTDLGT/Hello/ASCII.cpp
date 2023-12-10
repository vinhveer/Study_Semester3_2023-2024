#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i < 255; i++) {
        cout << i << ": "<<static_cast<char>(i) << endl;
    }
    return 0;
}