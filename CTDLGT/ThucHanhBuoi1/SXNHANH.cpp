#include <iostream>
using namespace std;

#define ll long long

void Partition(int a[], int l, int r)
{
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap(a[i], a[r]);
    for (int k = 0; k <= r; k++)
    {
        if (k == i)
            cout << "[" << a[k] << "] ";
        else
            cout << a[k] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Partition(a, 0, n - 1);

    return 0;
}
