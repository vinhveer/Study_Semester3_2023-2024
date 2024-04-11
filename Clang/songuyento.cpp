#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t n;
	cin >> n;
	if (n == 2)
	{
		cout << "YES";
		return 0;
	}
	else if (n % 2 == 0 || n < 2)
	{
		cout << "NO";
		return 0;
	}
	else
	{
		int k = sqrt(n);
		for (int i = 2; i <= k; i++)
		{
			if (n % i == 0)
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}