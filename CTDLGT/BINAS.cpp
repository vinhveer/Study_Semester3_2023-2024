#include <iostream>
using namespace std;

#define MAX 50

int n;
int a[MAX];

void PrintResult()
{
    for (int j = 1; j <= n; j++)
    {
        cout << a[j];
    }
    cout << endl;
}

void TryPrint(int i)
{
    if (i > n)
    {
        PrintResult();
        return;
    }
    a[i] = 0;
    TryPrint(i + 1);
    a[i] = 1;
    TryPrint(i + 1);
}

int main()
{
    cin >> n;
    TryPrint(1);
    return 0;
}
