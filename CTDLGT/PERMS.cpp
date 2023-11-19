#include <iostream>
using namespace std;

#define MAX 50

int n;
int a[MAX];
int b[MAX];
int count;

int Factorial(int n)
{
    if (n == 0)
        return 1;
    return n * Factorial(n - 1);
}

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

    for (int j = 1; j <= n; j++)
    {
        if (b[j] == 0)
        {
            a[i] = j;
            b[j] = 1;
            TryPrint(i + 1);
            b[j] = 0;
        }
    }
}

int main()
{
    cin >> n;
    cout << Factorial(n) << endl;
    TryPrint(1);
    return 0;
}