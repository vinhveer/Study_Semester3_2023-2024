#include <iostream>
using namespace std;

int frac(int n)
{
	int sum = 1;
	for (int i = 1; i <= n; i++)
	{
		sum *= i;
	}
	
	return sum;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << "Tong: " << a + b << endl;
	cout << "Hieu: " << a - b << endl;
	cout << "Tich: " << a * b << endl;
	cout << "Thuong: " << (b != 0 ? to_string(a / b) : "Khong the chia cho 0") << endl;
	
	int n;
	cin >> n;
	cout << "Giai thua: " << frac(n) << endl;
	return 0;
}
