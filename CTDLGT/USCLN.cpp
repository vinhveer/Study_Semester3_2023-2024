#include <iostream>
using namespace std;

long long int FindGCD(long long int a, long long int b)
{
    if (b == 0)
        return a;
    else
        return FindGCD(b, a % b);
}

int main()
{
    long long int a, b;
    cin >> a >> b;
    cout << FindGCD(a, b);
}