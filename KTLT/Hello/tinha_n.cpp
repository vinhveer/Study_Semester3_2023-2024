#include <iostream>
using namespace std;

long long int LuyThua(long long int a, long long int n)
{
    if (n == 0)
        return 1;
    long long int temp = LuyThua(a, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    else
        return temp * temp * a;
}

int main()
{
    long long int a, n;
    cout << "Enter base (a): ";
    cin >> a;
    cout << "Enter exponent (n): ";
    cin >> n;

    cout << "Result: " << LuyThua(a, n) << endl;

    return 0;
}
