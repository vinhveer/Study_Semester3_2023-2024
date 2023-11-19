#include <iostream>
#include <vector>
using namespace std;

int MaxRevenue(vector<int> &array)
{
	int sum_max = INT_MIN;
	int sum;
	for (int i = 0; i < array.size(); i++)
	{
		int sum = 0;
		for (int j = i; j < array.size(); j++)
		{
			sum += array[j];
			if (sum_max < sum)
				sum_max = sum;
		}

		
	}

	return sum_max;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<int> array;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		array.push_back(temp);
	}

	cout << MaxRevenue(array);

	return 0;
}