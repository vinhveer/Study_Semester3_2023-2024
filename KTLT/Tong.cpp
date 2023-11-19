#include <iostream>
using namespace std;

int Tong(int a[], int n)
{
    if (n == 0)
    {
        if (a[n] > 0)
            return a[n];
        else
            return 0;
    }
    else
    {
        if (a[n] > 0)
            return a[n] + Tong(a, n - 1);
        else
            return Tong(a, n - 1);
    }
}

int main()
{
    int n;
    int a[100];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << Tong(a, n - 1);
    return 0;
}