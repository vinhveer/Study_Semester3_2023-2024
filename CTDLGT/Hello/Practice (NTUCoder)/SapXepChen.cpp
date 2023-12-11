#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {   
        int pos = i - 1, value = a[i];
        while (pos >= 0 && value < a[pos])
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = value;
        cout << a[pos + 1] << " " << pos + 1 << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    InsertionSort(a, n);
}
