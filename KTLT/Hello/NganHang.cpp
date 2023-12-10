#include <iostream>
#include <iomanip>
using namespace std;

float LaiSuat(float n)
{
    if (n == 0)
        return 100;
    return 1.06 * LaiSuat(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << setprecision(2) << fixed << LaiSuat(n) << endl;
    return 0;
}