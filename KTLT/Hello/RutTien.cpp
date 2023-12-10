#include <iostream>
using namespace std;

#define N 50

int t[N];
int x[N];
int n;

void Print()
{
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int i, int S)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n - 1)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += x[k] * t[k];
            }
            if (sum == S)
            {
                Print();
            }
        }
        else
        {
            Try(i + 1, S);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    int S;
    cin >> S;
    
    Try(0, S);
    
    return 0;
}