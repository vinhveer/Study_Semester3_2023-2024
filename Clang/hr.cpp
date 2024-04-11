#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

void selection_sort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main()
{
    srand(time(NULL)); // Khởi tạo seed cho hàm rand()

    int n = 100000; // Kích thước mảng
    int arr1[n], arr2[n];

    // Sinh ngẫu nhiên các phần tử của mảng
    for (int i = 0; i < n; i++)
    {
        arr1[i] = rand() % n;
        arr2[i] = arr1[i];
    }

    // Sắp xếp bằng Selection Sort
    auto start_time1 = chrono::high_resolution_clock::now();          // Lấy thời điểm bắt đầu sắp xếp
    thread t1(selection_sort, arr1, n);                               // Tạo một thread để sắp xếp mảng bằng Selection Sort
    t1.join();                                                        // Đợi thread hoàn thành
    auto end_time1 = chrono::high_resolution_clock::now();            // Lấy thời điểm kết thúc sắp xếp
    chrono::duration<double> elapsed_time1 = end_time1 - start_time1; // Tính thời gian thực hiện

    // Sắp xếp bằng Bubble Sort
    auto start_time2 = chrono::high_resolution_clock::now();          // Lấy thời điểm bắt đầu sắp xếp
    thread t2(bubble_sort, arr2, n);                                  // Tạo một thread để sắp xếp mảng bằng Bubble Sort
    t2.join();                                                        // Đợi thread hoàn thành
    auto end_time2 = chrono::high_resolution_clock::now();            // Lấy thời điểm kết thú
    chrono::duration<double> elapsed_time2 = end_time2 - start_time2; // Tính thời gian thực hiện

    // In ra kết quả
    cout << "Selection Sort: " << elapsed_time1.count() << " seconds." << endl;
    cout << "Bubble Sort: " << elapsed_time2.count() << " seconds." << endl;

    return 0;
}