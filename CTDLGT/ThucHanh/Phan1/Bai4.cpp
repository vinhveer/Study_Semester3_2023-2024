#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "N = ";
    cin >> n;
    int length = 1;
    int space = n - 1;
    while (space > -1)
    {
        for (int j = 0; j < space; j++)
            cout << " ";
        space--;

        for (int k = 0; k < length; k++)
            cout << "*";
        length += 2;

        cout << endl;
    }

    return 0;
}