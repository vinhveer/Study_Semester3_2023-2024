#include <iostream>
using namespace std;

void PhanTich(int n)
{
    if (n == 1)
        cout << n;
    else
    {
        int i = 2;
        while (n % i != 0)
            i++;
        cout << i << "*";
        PhanTich(n / i);
    }
}

int main()
{
    int n;
    cout << "Nhap vao mot so nguyen duong: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Vui long nhap mot so nguyen duong." << endl;
        return 1;
    }

    cout << "Phan tich thanh thua so nguyen to cua " << n << " la: ";
    PhanTich(n);
    cout << endl;

    return 0;
}
