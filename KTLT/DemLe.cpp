#include <iostream>
using namespace std;

int DemLe(int n, int a[])
{
    if (n == 0)
        return (a[n] > 0) ? 1 : 0;
    if (a[n] > 0)
        return DemLe(n - 1, a) + 1;
    return DemLe(n - 1, a);
}

int main()
{
    int n;
    int a[100];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << DemLe(n - 1, a);
    return 0;
}
