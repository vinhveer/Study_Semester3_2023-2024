#include <iostream>
using namespace std;

#define ll long long

void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void XuatMang(int a[], int n, int index1 = -1, int index2 = -1)
{
    for (int k = 0; k < n; k++)
    {
        if (k == index1 || k == index2)
        {
            cout << "[" << a[k] << "] ";
        }
        else
            cout << a[k] << ' ';
    }
    cout << endl;
}

void SapXepChon(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[index])
                index = j;
        }
        swap(a[index], a[i]);
        XuatMang(a, n, index, i);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    NhapMang(a, n);

    SapXepChon(a, n);

    return 0;
}