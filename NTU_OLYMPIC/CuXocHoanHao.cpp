#include <bits/stdc++.h>
using namespace std;

vector<int> xd(vector<int> a)
{
    vector<int> b(52);
    int k = 0;
    for (int i = 1; i <= 26; i++)
    {
        b[k] = a[i + 26 - 1];
        b[k + 1] = a[i - 1];
        k += 2;
    }
    return b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> a(52);
    for (int i = 1; i <= 52; i++)
        a[i - 1] = i;
    int n;
    cin >> n;
    while (n--)
        a = xd(a);
    for (auto u : a)
        cout << u << " ";
    return 0;
}