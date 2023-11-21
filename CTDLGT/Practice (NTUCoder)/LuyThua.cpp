#include <iostream>
using namespace std;

#define ll long long

int mod = 1e4;
ll Calculate(ll a, ll b)
{
    if (b == 0)
        return 1;
    else
    {
        ll x = Calculate(a, b / 2);
        if (b % 2 == 0)
            return (x % mod) * (x % mod) % mod;
        else
            return ((x % mod) * (x % mod) % mod) * (a % mod) % mod;
    }
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << Calculate(a, b);
}