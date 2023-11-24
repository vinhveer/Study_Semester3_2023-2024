#include <iostream>
using namespace std;

int x;
int Count(int a[], int left, int right)
{
    if (left == right)
    {
        if (a[right] == x)
            return 1;
        else return 0;
    }
    else
    {
        int m = (left + right) / 2;
        return Count(a, left, m) + Count(a, m + 1, right);
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

    cout << "x = ";
    cin >> x;
    cout << "So lan xuat hien: " << Count(a, 0, n - 1) << endl;

    return 0;
}
