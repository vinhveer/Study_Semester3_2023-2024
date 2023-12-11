#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int l, r, a, k;
    cin >> l >> r >> a >> k;
    
    long long int count = 0;

    for (long long int s = l; s <= r; s++)
    {
        if ((a * s) % k == 0)
        {
            count++;
        }
    }

    cout << count;

    return 0;
}