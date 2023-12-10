#include <iostream>
using namespace std;

void InputOutput()
{
    int n, a[50];
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        count++;
    }
    cout << "Count: " << count;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    InputOutput();

    return 0;
}