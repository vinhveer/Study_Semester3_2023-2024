#include <iostream>
using namespace std;

void HaNoi(int n, char a, char b, char c)
{
    if (n == 1)
        cout << endl
             << a << "->"<< b;
    else
    {
        HaNoi(n - 1, a, c, b);
        cout << endl << a << "->"<< b;
        HaNoi(n - 1, c, b, a);
    }
}
int main()
{
    HaNoi(3, 'A', 'B', 'C');
}
