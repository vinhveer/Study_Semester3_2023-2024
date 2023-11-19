#include <iostream>

using namespace std;

int main()
{
    int m, n, t;
    cin >> m >> n >> t;
    cout << 1ll * (n - n / (m + 1)) * t << "\n";

    return 0;
}
