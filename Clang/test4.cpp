#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

// Hàm sắp xếp bằng thuật toán Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

// Hàm sắp xếp bằng thuật toán Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main()
{
    srand(time(NULL)); // Khởi tạo seed cho hàm random

    const int n = 10000;
    int arr1[n], arr2[n];

    // Sinh ngẫu nhiên mảng arr1
    for (int i = 0; i < n; i++)
        arr1[i] = rand() % 100;

    // Sao chép arr1 sang arr2
    for (int i = 0; i < n; i++)
        arr2[i] = arr1[i];

    // In mảng arr1 trước khi sắp xếp
    cout << "Mang truoc khi sap xep:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;

    // Tạo 2 thread để sắp xếp hai mảng bằng hai thuật toán khác nhau
    auto start1 = chrono::steady_clock::now(); // Lấy thời điểm bắt đầu thực hiện Selection Sort
    thread t1(selectionSort, arr1, n);
    auto start2 = chrono::steady_clock::now(); // Lấy thời điểm bắt đầu thực hiện Bubble Sort
    thread t2(bubbleSort, arr2, n);

    // Chờ hai thread hoàn thành
    t1.join();
    t2.join();

    // In mảng arr1 và arr2 sau khi sắp xếp
    cout << "Mang sau khi sap xep bang Selection Sort:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;

    cout << "Mang sau khi sap xep bang Bubble Sort:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    cout << endl;

    // Tính thời gian hoàn thành của hai thuật toán
    auto end1 = chrono::steady_clock::now(); // Lấy thời
    auto end2 = chrono::steady_clock::now(); // Lấy thời điểm kết thúc
    auto diff1 = end1 - start1;              // Tính khoảng thời gian hoàn thành Selection Sort
    auto diff2 = end2 - start2;              // Tính khoảng thời gian hoàn thành Bubble Sort

    cout << "Thoi gian hoan thanh Selection Sort: " << chrono::duration<double, milli>(diff1).count() << " ms" << endl;
    cout << "Thoi gian hoan thanh Bubble Sort: " << chrono::duration<double, milli>(diff2).count() << " ms" << endl;

    return 0;
}