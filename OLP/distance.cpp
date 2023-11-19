#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void InputArray(vector<int64_t> &array, int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        array.push_back(temp);
    }
}

int64_t CalculateDistance(vector<int64_t> a, vector<int64_t> b)
{
    vector<int64_t> c;
    c.clear();
    int l, r;
    cin >> l >> r;
    for (int i = l - 1; i < r; i++)
    {
        c.push_back(a[i]);
    }

    int64_t min = abs(c[0] - b[0]);
    for (int i = 0; i < c.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            int64_t temp = abs(c[i] - b[j]);
            if (temp < min)
                min = temp;
        }
    }

    return min;
}

int main()
{
    vector<int64_t> a;
    vector<int64_t> b;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    int64_t c[k];

    InputArray(a, n);
    InputArray(b, m);

    for (int i = 0; i < k; i++)
    {
        int64_t temp = CalculateDistance(a, b);
        cout << temp << endl;
    }
    return 0;
}
