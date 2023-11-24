#include <iostream>
using namespace std;

int Sum(int a[], int left, int right)
{
    if (left == right)
        return a[left];
    else
    {
        int m = (left + right) / 2;
        return Sum(a, left, m) + Sum(a, m + 1, right);
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

    cout << "Tong cac phan tu cua mang: " << Sum(a, 0, n - 1) << endl;

    return 0;
}
