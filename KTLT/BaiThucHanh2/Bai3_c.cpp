#include <iostream>
using namespace std;

int CountChar(int n)
{
	if (n < 10)
		return 1;
	return 1 + CountChar(n / 10);
}

int main()
{
	int n;
	do
	{
		cout << "N = ";
		cin >> n;	
	} while (n < 10 || n > 100000);

	cout << "Tong chu so: " << CountChar(n) << endl;
	return 0;
}