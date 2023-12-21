#include <iostream>
using namespace std;

#define MAX 30

int x[MAX];
int n;

void Print()
{
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        x[i] = j;
        if (i == n)
            Print();
        else
            Try(i + 1);
    }
}

int main()
{
    cin >> n;
    Try(0);
}