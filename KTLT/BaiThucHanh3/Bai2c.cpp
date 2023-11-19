#include <iostream>
using namespace std;

void lietKeChinhHop(int[], bool[], int, int, int);
void inChinhHop(int[], int);

int main() {
    int n, k;

    // Nhập giá trị của n và k
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    cout << "Nhap so nguyen duong k: ";
    cin >> k;

    // Kiểm tra điều kiện hợp lệ
    if (k <= 0 || n <= 0 || k > n) {
        cout << "Nhap gia tri khong hop le." << endl;
        return 1;
    }

    int mangChinhHop[k];
    bool daSuDung[n + 1] = {false};

    cout << "Cac chinh hop khong lap chap " << k << " cua " << n << " la:" << endl;
    lietKeChinhHop(mangChinhHop, daSuDung, n, k, 1);

    return 0;
}

void lietKeChinhHop(int mangChinhHop[], bool daSuDung[], int n, int k, int buoc) {
    if (buoc > k) {
        inChinhHop(mangChinhHop, k);
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!daSuDung[i]) {
            daSuDung[i] = true;
            mangChinhHop[buoc - 1] = i;
            lietKeChinhHop(mangChinhHop, daSuDung, n, k, buoc + 1);
            daSuDung[i] = false;
        }
    }
}

void inChinhHop(int mangChinhHop[], int k) {
    for (int i = 0; i < k; ++i) {
        cout << mangChinhHop[i] << " ";
    }
    cout << endl;
}
