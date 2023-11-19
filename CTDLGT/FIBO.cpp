#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    int f0 = 0;
    int f1 = 1;
    int fn;
    for (int i = 0; i < count; i++)
    {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
        cout << f0 << " ";
    }
    return 0;
}