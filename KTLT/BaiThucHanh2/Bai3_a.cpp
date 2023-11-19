#include <iostream>
using namespace std;

int LuyThua(int a, int n)
{
	if (n == 0)
		return 1;
	return a * LuyThua(a, n - 1);
}

int main()
{
	int a, n;
	cout << "a = ";
	cin >> a;
	cout << "n = ";
	cin >> n;

	cout << a << "^" << n << " =  " << LuyThua(a, n) << endl;
	
	return 0;
}
