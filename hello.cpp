#include <iostream>
using namespace std;

int DeQuy(int n)
{
    if (n == 1)
        return 1;
    return n + DeQuy(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << "Ket qua la: " << DeQuy(n) << endl;
    return 0;
}