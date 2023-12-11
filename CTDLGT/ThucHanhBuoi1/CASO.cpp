#include <iostream>
using namespace std;

#define ll long long
#define MAX 100000

int d[MAX];

int main()
{
    int n, amax = -1;
    ll ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        amax = max(amax, a[i]);
        d[a[i]]++;
    }

    for (int i = 1; i <= amax; i++)
        if (d[i] > 1)
            ans += 1ll * d[i] * 1ll * (d[i] - 1) / 2;

    cout << ans;
}
