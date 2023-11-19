#include <iostream>
using namespace std;

#define MAX 100

void Input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

int FindMax(int a[], int n)
{
	if (n == 0)
		return -1;
	if (n == 1)
		return a[0];
	else
		if (a[n - 1] > FindMax(a, n - 1))
			return a[n - 1];
		else
			return FindMax(a, n - 1);
}

int main()
{
	int n;
	int a[MAX];

	cout << "N = ";
	cin >> n;
	Input(a, n);

	cout << FindMax(a, n) << endl;
	return 0;
}
