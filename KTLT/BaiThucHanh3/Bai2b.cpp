#include <iostream>
using namespace std;

const int MAX_N = 50;

int x[MAX_N];
int k, n;

void KhoiTao()
{
    x[0] = 0;
}

void InNghiem(int n)
{
    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void TaoNghiem(int i)
{
    for (int j = x[i - 1] + 1; j <= n - k + i; j++)
    {
        x[i] = j;
        if (i == k)
            InNghiem(k);
        else
            TaoNghiem(i + 1);
    }
}

int main()
{
    cin >> k;
    cin >> n;

    KhoiTao();
    TaoNghiem(1);

    return 0;
}
