#include <iostream>
using namespace std;

int Pow(int a, int left, int right)
{
    if (left == right)
        return a;
    else
    {
        int m = (left + right) / 2;
        return Pow(a, left, m) * Pow(a, m + 1, right);
    }
}

int main()
{
    int a, n;
    cout << "a = ";
    cin >> a;
    cout << "n = ";
    cin >> n;
    cout << Pow(a, 1, n) << endl;   
    return 0;
}
