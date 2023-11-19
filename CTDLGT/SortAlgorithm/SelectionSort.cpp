#include <iostream>
using namespace std;

void InputArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
}

void OutputArray(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl; 
}

void SelectionSort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (arr[min] > arr[j])
				min = j;

		if (min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}	
}

int main()
{
	int n;
	cout << "Nhập số lượng phần tử: ";
	cin >> n;

	int *arr = new int[n];

	InputArray(arr, n);
	SelectionSort(arr, n);
	OutputArray(arr, n);

	delete[] arr;	
	return 0;
}
