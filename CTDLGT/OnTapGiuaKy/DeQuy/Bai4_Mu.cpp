#include <iostream>
using namespace std;

double Power(double x, int n)
{
    if (n == 0)
        return 1;
    double res = Power(x, n / 2);
    if (n % 2 == 1)
        return res * res * x;
    else
        return res * res;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << Power(x, n);
    return 0;
}