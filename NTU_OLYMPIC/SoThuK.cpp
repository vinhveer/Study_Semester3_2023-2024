#include <iostream>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int count = 0, i = 3;
	int k;
	cin >> k;

	while (count != k)
	{
		if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0)
		{
			count++;
			if (count == k)
				cout << i << endl;
		}
		i++;
	}
	return 0;
}