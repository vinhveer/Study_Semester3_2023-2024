#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    int v;
    int day = 0;
    cin >> a >> b >> v;
    while (v > b)
    {
        v = v - a + b;
        day++;
    }
    cout << day;
    return 0;
}