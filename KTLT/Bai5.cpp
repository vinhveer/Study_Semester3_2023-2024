#include <iostream>
using namespace std;

struct HocPhan
{
    string maHocPhan;
    string tenHocPhan;
    int soTinChi;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("HocPhan.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        HocPhan hocPhanN;
        cin >> hocPhanN.maHocPhan;
        cout << hocPhanN.maHocPhan;
        cin.ignore();
        cin >> hocPhanN.tenHocPhan;
        cout << hocPhanN.tenHocPhan;
        cin.ignore();
        cin >> hocPhanN.soTinChi;
        cout << hocPhanN.soTinChi;
    }

    return 0;
}