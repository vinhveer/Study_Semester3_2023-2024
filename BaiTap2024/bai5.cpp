#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Print(vector<int> numbers)
{
	for (int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> numbers = {3, 2, 5, 1, 6, 4, 7, 8, 9, 12, 11, 10, 18, 19};
	sort(numbers.begin(), numbers.end());
	Print(numbers);
	reverse(numbers.begin(), numbers.end());
	Print(numbers);

	return 0;
}
