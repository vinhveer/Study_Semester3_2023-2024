#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, index = 0, count = 0;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    if (m == 1)
    {
        cout << "0";
        return 0;
    }
    while (m > 0)
    {
        if (index == n)
        {
            cout << "-1";
            return 0;
        }
        if (m > a[index])
        {
            m = m - a[index] + 1;
            count++;
            index++;
        }
        else
        {
            m -= a[index];
            count++;
        }
    }
    cout << count;
}