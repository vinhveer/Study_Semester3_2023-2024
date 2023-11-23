#include <iostream>
#include <stack>

using namespace std;

void Prime(int n)
{
    stack<int> thuaSo;

    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            thuaSo.push(i);
            n /= i;
        }
    }

    if (n > 1)
    {
        thuaSo.push(n);
    }

    while (!thuaSo.empty())
    {
        cout << thuaSo.top();
        thuaSo.pop();
        if (!thuaSo.empty())
        {
            cout << "*";
        }
    }

    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    Prime(n);

    return 0;
}
