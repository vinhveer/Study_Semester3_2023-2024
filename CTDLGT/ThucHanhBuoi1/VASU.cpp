#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (a[i] - i > 0)
        {
            sum += a[i] - i;
        }
    }
    cout << sum;
    return 0;
}
