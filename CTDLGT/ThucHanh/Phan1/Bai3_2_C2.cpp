#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "N = ";
    cin >> n;
    int x = n - 1;
    int y = n - 1;
    int length = n + (n - 1);
    int space = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (j == x || j == y)
                cout << "*";
            else
                cout << " ";
        }

        x--;
        y++;
        cout << endl;
    }

    for (int i = 0; i < length; i++)
        cout << "*";
    
    cout << endl;
    return 0;
}