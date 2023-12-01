#include <iostream>
using namespace std;

int BinarySearch(int arr[], int low, int high, int x)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return BinarySearch(arr, low, mid - 1, x);

        return BinarySearch(arr, mid + 1, high, x);
    }

    return -1;
}

int FindElement(int arr[], int n, int x)
{
    return BinarySearch(arr, 0, n - 1, x);
}

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;

    int result = FindElement(arr, n, x);

    if (result != -1)
        cout << "Phan tu " << x << " duoc tim thay tai vi tri " << result << endl;
    else
        cout << "Phan tu " << x << " khong tim thay trong mang.\n";

    return 0;
}
