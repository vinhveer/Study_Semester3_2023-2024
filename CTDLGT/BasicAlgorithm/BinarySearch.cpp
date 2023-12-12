#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Nếu phần tử ở giữa là target, trả về vị trí của nó
        if (arr[mid] == target)
        {
            return mid;
        }

        // Nếu target nằm bên phải của phần tử ở giữa, thì tìm kiếm bên phải
        if (arr[mid] < target)
        {
            left = mid + 1;
        }

        // Nếu target nằm bên trái của phần tử ở giữa, thì tìm kiếm bên trái
        else
        {
            right = mid - 1;
        }
    }

    // Nếu không tìm thấy target trong mảng, trả về -1
    return -1;
}

int main()
{
    // Mảng đã sắp xếp (yêu cầu mảng đã được sắp xếp để sử dụng Binary Search)
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int target;
    cout << "Nhập giá trị cần tìm: ";
    cin >> target;

    int result = binarySearch(arr, target);

    if (result != -1)
    {
        cout << "Phần tử " << target << " được tìm thấy tại vị trí " << result << endl;
    }
    else
    {
        cout << "Không tìm thấy phần tử " << target << " trong mảng" << endl;
    }

    return 0;
}
