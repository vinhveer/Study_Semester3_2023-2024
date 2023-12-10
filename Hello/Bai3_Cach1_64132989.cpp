#include <iostream>
using namespace std;

double BestScore(int n, double a[], double max)
{
	if (n == -1)
		return max;
	if (a[n] > max)
		max = a[n];
	return BestScore(n - 1, a, max);
}

int main()
{
	#ifndef INPUT_OUTPUT
	freopen("input.txt", "r+", stdin);
	freopen("output.txt", "w+", stdout);
	#endif
	
	double a[50];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	double max = a[0];
	cout << "Mark: " << BestScore(n, a, max);
	
	return 0;
}
