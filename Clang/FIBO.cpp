#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f, f1 = 1, f2 = 1, n, count = 1;
    cin >> n;
    cout << 1 << " ";
    while (count < n)
    {
        count++;
        f = f1 + f2;
        f1 = f2;
        f2 = f;
        cout << f1 << " ";
    }
}