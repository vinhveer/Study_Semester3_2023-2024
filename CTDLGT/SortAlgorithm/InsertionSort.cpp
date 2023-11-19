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

void InsertionSort(int *arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[i] > temp)
		{	
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

int main()	
{
	int n;
	cout << "Nhập số lượng phần tử: ";
	cin >> n;

	int *arr = new int[n];

	InputArray(arr, n);
	InsertionSort(arr, n);
	OutputArray(arr, n);

	delete[] arr;
	return 0;
}
