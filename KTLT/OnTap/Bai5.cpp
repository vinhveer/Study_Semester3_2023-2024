#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int n;
int a[MAX], length[MAX], length_max;

void Solve()
{
    for (int i = 0; i < n; i++)
    {
        length_max = 0;
        for (int j = 0; j < i; j++)
            if (a[i] < a[j] && length_max < length[j])
                length_max = length[j];

        length[i] = length_max + 1;
    }
    cout << *max_element(length, length + n);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Solve();
}