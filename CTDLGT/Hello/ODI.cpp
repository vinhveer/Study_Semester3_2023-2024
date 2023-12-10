#include <iostream>
#include <algorithm>
using namespace std;

void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int FindMin(int a[], int n, int m)
{
    int i = 0;
    int count = 0;
    while (count < m && i < n)
    {
        count += a[i] - 1;
        i++;
    }
    return (count < m) ? -1 : i;
}

int main()
{
    int a[100];
    int n;
    int m;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sort(a, a + n, greater<int>());

    PrintArray(a, n);

    cout << FindMin(a, n, m);
    return 0;
}
