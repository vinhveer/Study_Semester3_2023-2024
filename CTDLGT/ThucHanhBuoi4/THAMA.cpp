#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    int a[2000];

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int i = n, kq = 0;

    while (i > 0)
    {
        kq += (a[i] - 1) * 2;

        i -= k;
    }

    cout << kq;
    return 0;
}