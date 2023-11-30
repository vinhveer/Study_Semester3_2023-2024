#include <iostream>
using namespace std;

void findVachSon(int n, int m, int distances[])
{
    int i = 0, j = 1;

    while (j < n)
    {
        if (distances[j] - distances[i] == m)
        {
            cout << distances[i] << " " << distances[j] << endl;
            return;
        }
        else if (distances[j] - distances[i] > m)
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

    int distances[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> distances[i];
    }

    findVachSon(n, m, distances);

    return 0;
}
