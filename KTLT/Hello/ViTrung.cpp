#include <iostream>
using namespace std;

int ViTrung(int n)
{
    if (n == 0)
        return 2;
    return 2 * ViTrung(n - 1);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;
    cout << ViTrung(n);
    return 0;
}