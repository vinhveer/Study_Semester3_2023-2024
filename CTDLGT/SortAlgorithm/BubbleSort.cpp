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

void BubbleSort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < i; j++)
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
}

int main()	
{
	int n;
	cout << "Nhập số lượng phần tử: ";
	cin >> n;

	int *arr = new int[n];

	InputArray(arr, n);
	BubbleSort(arr, n);
	OutputArray(arr, n);

	delete[] arr;
	return 0;
}
