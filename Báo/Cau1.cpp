#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

void ThuaSoNguyenTo(int n)
{
    stack<int> thuaSo;

    while (n % 2 == 0)
    {
        thuaSo.push(2);
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            thuaSo.push(i);
            n /= i;
        }
    }

    if (n > 2)
    {
        thuaSo.push(n);
    }

    cout << "Thua so nguyen to cua " << n << ": ";
    while (!thuaSo.empty())
    {
        cout << thuaSo.top() << " ";
        thuaSo.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    ThuaSoNguyenTo(n);

    return 0;
}