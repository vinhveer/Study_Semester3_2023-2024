#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[min_idx], arr[i]);
        for (int k = 0; k < n; k++) {
            if (k == min_idx || k == i) {
                cout << "[" << arr[k] << "]" << " ";
            } else {
                cout << arr[k] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int arr[20];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, n);
    return 0;
}