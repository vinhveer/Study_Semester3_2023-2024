#include <iostream>
using namespace std;

#define MAX 100

void InputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void OutputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

bool PerfectSquare(int n)
{
    int i = 0;
    while (i * i <= n)
    {
        if (i * i == n)
            return true;
        ++i;
    }
    return false;
}

int main()
{
#ifndef INPUT
    freopen("Lab2_1.inp", "r", stdin);
#endif

    int a[MAX];
    int n;
    cin >> n;
    cout << "So luong pha tu trong mang: " << n << endl;

    InputArray(a, n);
    OutputArray(a, n);

#ifndef OUTPUT
    freopen("Lab2_1.out", "w", stdout);
#endif

    int count = 0;
    for (int i = 0; i < n; i++)
        if (PerfectSquare(a[i]))
        {
            cout << a[i] << " ";
            count++;
        }
        
    if (count == 0)
        cout << -1 << endl;
    else
        cout << endl;

    count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] % 2 != 0)
        {
            count++;
            sum += a[i];
        }

    cout << "TBC: " << sum / count << endl;
    cout << "Số lượng số lẻ: " << count << endl;

    return 0;
}