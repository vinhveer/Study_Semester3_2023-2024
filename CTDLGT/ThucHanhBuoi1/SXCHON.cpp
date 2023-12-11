#include <iostream>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[index])
                index = j;
        }
        swap(a[index], a[i]);
        for (int k = 0; k < n; k++)
        {
            if (k == index || k == i)
            {
                cout << "[" << a[k] << "] ";
            }
            else
                cout << a[k] << ' ';
        }
        cout << endl;
    }

    return 0;
}