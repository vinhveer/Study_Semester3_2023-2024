#include <iostream>
using namespace std;

void HaNoi(int n, char a, char b, char c)
{
    if (n == 1)
        cout << endl
             << a << "->"<< b;
    else
    {
        HaNoi(n - 1, a, c, b);
        cout << endl << a << "->"<< b;
        HaNoi(n - 1, c, b, a);
    }
}
int main()
{
	int n;
	cout << "Nhap so luong dia: ";
	cin >> n;
    HaNoi(n, 'A', 'B', 'C');
    return 0;
}
