#include <iostream>
#include <vector>

using namespace std;

void phanTichSo(int[], int, int, int);

int main()
{
    int n;

    // Nhập giá trị của n
    cout << "Nhap so nguyen duong n (n < 20): ";
    cin >> n;

    // Kiểm tra điều kiện hợp lệ
    if (n <= 0 || n >= 20)
    {
        cout << "Nhap gia tri khong hop le." << endl;
        return 1;
    }

    int mangPhanTich[n];
    phanTichSo(mangPhanTich, n, 0, 1);

    cout << "Ket qua phan tich so " << n << " la:" << endl;

    return 0;
}

void phanTichSo(int mangPhanTich[], int n, int tong, int buoc)
{
    if (tong == n)
    {
        // In ra một cách phân tích
        for (int i = 0; i < buoc - 1; ++i)
        {
            cout << mangPhanTich[i] << " + ";
        }
        cout << mangPhanTich[buoc - 1] << endl;
        return;
    }

    for (int i = 1; i <= n - tong; ++i)
    {
        mangPhanTich[buoc - 1] = i;
        phanTichSo(mangPhanTich, n, tong + i, buoc + 1);
    }
}
