#include <iostream>
using namespace std;

#define MAX 100

int x[MAX];
int n;
int k;

void Print()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (x[i] == 1)
            sum++;
    if (sum >= k)
    {
        for (int i = 0; i < n; i++)
            cout << (x[i] == 0 ? "_" : "x");
        cout << endl;
    }
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++)
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
    cin >> k;
    Try(0);
    return 0;
}
