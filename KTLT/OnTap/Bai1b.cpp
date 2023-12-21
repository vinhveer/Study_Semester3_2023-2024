#include <iostream>
using namespace std;

bool Check(int n)
{
    if (n == 0)
        return true;
    if ((n % 10) % 2 != 0)
        return false;
    else 
        return Check(n / 10);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        if (Check(i))
            cout << i << " ";
    return 0;
}
