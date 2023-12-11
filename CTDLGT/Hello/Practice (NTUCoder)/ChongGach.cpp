#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, gh = 1e9, res = 0;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        res++;
        gh = min(gh - 1, a[i]);
        if (gh == 0)
        {
            cout << res;
            return 0;
        }
    }
}
