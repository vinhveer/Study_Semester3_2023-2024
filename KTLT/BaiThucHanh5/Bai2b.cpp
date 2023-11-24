#include <iostream>
using namespace std;

int Max(int a[], int left, int right)
{
    if (left == right)
    {
        return right;
    }
    else
    {
        int m = (left + right) / 2;
        int maxLeft = Max(a, left, m);
        int maxRight = Max(a, m + 1, right);
        return (a[maxLeft] > a[maxRight]) ? maxLeft : maxRight;
    }
}

int main()
{
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "Vi tri co so lon nhat: " << Max(a, 0, n - 1) << endl;

    return 0;
}