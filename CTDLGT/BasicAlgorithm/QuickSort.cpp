#include <iostream>
#include <vector>

using namespace std;

// Hàm hoán đổi giá trị của hai phần tử
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Hàm partition để chia mảng thành hai phần và trả về chỉ số của phần tử chốt
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Chọn phần tử chốt
    int i = low - 1;       // Chỉ số của phần tử nhỏ hơn phần tử chốt

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm sắp xếp Quick Sort
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // Tìm phần tử chốt, arr[p] đang ở đúng vị trí
        int p = partition(arr, low, high);

        // Gọi đệ quy để sắp xếp các phần tử nhỏ hơn và lớn hơn phần tử chốt
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Hàm in mảng
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {12, 7, 11, 5, 6, 13, 6};
    int n = arr.size();

    cout << "Mang truoc khi sap xep: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    printArray(arr);

    return 0;
}
