#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x, m = 1;
    int64_t n;
    cin >> x >> n;
    if (n == 1 || x == 1)
    {
        cout << x;
        return 0;
    }
    int y = log2(n);
    int ar[y] = {x};
    for (int i = 1; i <= y; i++)
        ar[i] = (ar[i - 1] * ar[i - 1]) % 10000;
    while (n > 0)
    {
        int p = log2(n);
        n -= int64_t(pow(2, p));
        m *= ar[p];
        m %= 10000;
    }
    cout << m;
    return 0;
}