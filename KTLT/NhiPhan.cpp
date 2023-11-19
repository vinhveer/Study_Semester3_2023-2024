#include <iostream>
using namespace std;
int n;
int a[100];

void Print()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void NhiPhan(int i)
{
    if (i == n)
    {
        Print();
        return;
    }

    a[i] = 0;
    NhiPhan(i + 1);
    a[i] = 1;
    NhiPhan(i + 1);
}

int main()
{
    
    cin >> n;
    NhiPhan(0);

    return 0;
}