#include <iostream>
using namespace std;

int CountRabbit(int n)
{
	if (n <= 0)
		return 0;
	else if (n == 1 || n == 2)
		return 2;
	else
		return CountRabbit(n - 1) + CountRabbit(n - 2);
}

int main()
{
	int n;
	cout << "N = ";
	cin >> n;
	cout << "So luong tho: " << CountRabbit(n) << endl;
	return 0;
}
