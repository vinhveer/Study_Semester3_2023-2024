#include <iostream>
using namespace std;

void printaay(int a[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && key < a[j]) {
            a[j + 1] = a[j];
            --j;
        }

        a[j + 1] = key;
        printaay(a, n);
    }
}

int main() {
    int n;
    cin >> n;

    int a[20]; // Chọn kích thước tối đa của mảng là 20, nhưng bạn có thể điều chỉnh nếu cần thiết

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    insertionSort(a, n);

    return 0;
}
