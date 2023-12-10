#include <iostream>
using namespace std;

inline int Min(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

int main()
{
	int a, b, c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	if (Min(a, b) == a && Min(a, c) == a)
		cout << a;
	else if (Min(b, a) == b && Min(b, c) == b)
		cout << b;
	else
		cout << c;
		
	return 0;
}
