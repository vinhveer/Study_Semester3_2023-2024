#include <iostream>
using namespace std;

void A(int n)
{
    cout << n;
    A(n + 1);
    A(n + 2);
}
int main()
{
    A(5);
}
