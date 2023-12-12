#include <iostream>
#include <vector>

using namespace std;

// Hàm merge để kết hợp hai mảng đã sắp xếp thành một mảng mới đã sắp xếp
void merge(vector<int> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Tạo các mảng tạm để lưu trữ dữ liệu
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    // Sao chép dữ liệu vào các mảng tạm
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middle + 1 + j];

    // Gộp các mảng tạm vào mảng chính
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của leftArray (nếu có)
    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của rightArray (nếu có)
    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Hàm thực hiện thuật toán merge sort
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Tìm điểm giữa mảng
        int middle = left + (right - left) / 2;

        // Gọi đệ quy cho nửa đầu tiên và nửa thứ hai của mảng
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Gộp hai nửa đã sắp xếp
        merge(arr, left, middle, right);
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    // Gọi hàm mergeSort để sắp xếp mảng
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
