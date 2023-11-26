#include <iostream>
#include <math.h>
using namespace std;

int Check(int n)
{
    if (n == 2)
        return 1;
    else if (n % 2 == 0)
        return 0;
    else if (n % 3 == 0)
        return 0;
    else
        for (int i = 4; i < sqrt(n); i++)
            if (n % i == 0)
                return 0;
    return 1;
}

int main()
{
    int n;
    cout << "N = ";
    cin >> n;
    for (int i = 2; i < n; i++)
        if (Check(i) == 1)
            cout << i << " ";
    return 0;
}