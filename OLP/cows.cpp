#include <iostream>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	double n, S;
	cin >> n >> S;

	sum = ((1 + n) * n) / 2;

	cout << sum - S;

	return 0;
}