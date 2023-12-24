#include <iostream>
using namespace std;

#define MAX 100

int Count(float a[], int n, int count)
{
	if (n == 0)
		return count;
	if (int(a[n]) % 2 != 0)
		return Count(a, n - 1, count + 1);
	else
		return Count(a, n - 1, count);
	
}

int main()
{
	int n;
	do
	{
		cout << "N = ";
		cin >> n;
		if (n <= 2 || n >= 40)
			cout << "Gia tri n khong hop le!";
	} 
	while(n <= 2 || n >= 40);

	float a[MAX];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	int count = 0;
	cout << Count(a, n, count);
	return 0;
}
