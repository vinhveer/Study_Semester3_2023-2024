#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void InputArray(vector<int> &array, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		array.push_back(temp);
	}
}

void SortArray(vector<int> &array, int n)
{
	for(int i = 0; i< n-1; i++)	
	{
	    int k = i;
	    for(int j = i+1; j< n; j++)
		 if (array[j]< array[k])
			k = j;
	    if (k!=i) swap(array[k], array[i]);
	}
}

int CountHappy(vector<int> &array, int n)
{
	int countHappy = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (array[i] < array[i + 1])
		{
			countHappy++;
		}
	}
	return countHappy;
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

	InputArray(array, n);

	SortArray(array, n);

	cout << CountHappy(array, n);

	return 0;	
}