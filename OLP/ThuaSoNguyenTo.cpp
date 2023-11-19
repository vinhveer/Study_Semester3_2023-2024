#include <iostream>
using namespace std;

int UocSoNhoNhat(int number)
{
	for (int i = 2; i <= number; i++)
		if ((number % i) == 0)
			return i;
	return -1;
}

void Factor(int n)
{
	if (n == 1)
		cout << n;
	else
	{
		int uocSoNhoNhat = UocSoNhoNhat(n);
		cout << UocSoNhoNhat(n) << "*";
		Factor(n/uocSoNhoNhat);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin >> n;
	Factor(n);
	return 0;
}