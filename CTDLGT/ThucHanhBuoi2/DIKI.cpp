#include <iostream>
using namespace std;

void TimVachSon(int n, int m, int kcach[])
{
    int i = 0, j = 1;

    while (j < n)
    {
        if (kcach[j] - kcach[i] == m)
        {
            cout << kcach[i] << " " << kcach[j] << endl;
            return;
        }
        else if (kcach[j] - kcach[i] > m)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << -1 << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int kcach[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> kcach[i];
    }

    TimVachSon(n, m, kcach);

    return 0;
}
