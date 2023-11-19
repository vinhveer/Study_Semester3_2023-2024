#include <iostream>
using namespace std;

void Input(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int Sum(int n, int sum, int a[])
{
    if (n == -1)
        return sum;
    else 
        return Sum(n - 1, sum + a[n], a);
}

int main()
{
    #ifndef TEST
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    #endif

    int n;
    int a[100];

    cin >> n;
    Input(a, n);

    int sum = 0;
    cout << Sum(n - 1, sum, a); // Pass n-1 instead of n

    return 0;
}
