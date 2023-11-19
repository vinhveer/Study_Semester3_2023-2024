#include <iostream>
using namespace std;

int TongBP(int n)
{
	if (n == 1)
		return 1;
	return n*n + TongBP(n - 1);
}

int main()
{
	int n;
	cout << "n = ";
	cin >> n;

	cout << "Tong luy thua la:  " << TongBP(n) << endl;
	
	return 0;
}
