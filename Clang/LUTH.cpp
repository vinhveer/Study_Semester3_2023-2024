#include <bits/stdc++.h>
using namespace std;

int main()
{
    int64_t x, n;
    cin >> x >> n;

    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (res * x) % 10000;
        }
        x = (x * x) % 10000;
        n >>= 1;
    }

    cout << res << endl;
    return 0;
}
