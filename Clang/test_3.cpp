#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>

using namespace std;

// Hàm sắp xếp bằng thuật toán Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

// Hàm sắp xếp bằng thuật toán Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

int main() {
    srand(time(NULL)); // Khởi tạo seed cho hàm random

    const int n = 10;
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
    thread t1(selectionSort, arr1, n);
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

    return 0;
}
