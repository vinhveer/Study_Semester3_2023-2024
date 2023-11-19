#include <iostream>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int sum_square = 0;

	for (int i = 1; i < n + 1; i++)
		sum_square += i * i;

	cout << sum_square;

	return 0;
}