#include <iostream>
using namespace std;

double Amount(int n, double amount)
{
    if (n == 0)
        return amount;
    return Amount(n - 1, amount + 100000 * (6.5 / 100.0)); 
}

double Amount(int n)
{
    if (n == 0)
        return 100000;
    return 1.065*Amount(n - 1);
}

int main()
{
    #ifndef TEST
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    #endif

    int n;
    cin >> n;
    double amount = 100000;

    cout << Amount(n);

    return 0;
}
