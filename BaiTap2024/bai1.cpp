#include <iostream>
using namespace std;

int main()
{
    string n;
    cin >> n;

    cout << "Số lượng chữ số: << n.length() << endl;
    for (int i = 0; i < n.length(); i++)
    {
        cout << n[i] << " ";
    }

    return 0;
}
