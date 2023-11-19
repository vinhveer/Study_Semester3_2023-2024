#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "N = ";
    cin >> n;
    int max_length = n + (n - 1);
    for (int i = n; i > -1; i--)
    {
        for (int j = 0; j < i; j++)
            cout << " ";

        for (int k = 0; k < (max_length - (i * 2)); k++)
            cout << "*";
        
        cout << endl;
    }

    return 0;
}