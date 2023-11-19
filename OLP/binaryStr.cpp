#include <iostream>
using namespace std;

#define MAX 100

int n, a[MAX];

void Print()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	cout << endl;
}

void Binary(int i)
{
	if (n == i)
	{
		Print();
		return;
	}

	a[i] = 0; Binary(i + 1);
	a[i] = 1; Binary(i + 1);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	cin >> n;
	Binary(0);
	return 0;
}