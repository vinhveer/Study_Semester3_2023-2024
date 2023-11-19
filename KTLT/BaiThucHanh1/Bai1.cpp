#include <iostream>
#include <vector>
using namespace std;

struct HocPhan
{
    string maHocPhan;
    string tenHocPhan;
    int soTinChi;
    float diemTrungBinh; // Changed to float to store decimal values for average score
};

void NhapMotHocPhan(vector<HocPhan> &hocPhan)
{
    HocPhan hocPhanMoi;

    cout << "Ma hoc phan: ";
    getline(cin, hocPhanMoi.maHocPhan);
    cout << "Ten hoc phan: ";
    getline(cin, hocPhanMoi.tenHocPhan);
    cout << "So tin chi: ";
    cin >> hocPhanMoi.soTinChi;
    cout << "Diem trung binh: ";
    cin >> hocPhanMoi.diemTrungBinh;

    hocPhan.push_back(hocPhanMoi);
}

void XuatMotHocPhan(vector<HocPhan> &hocPhan, int chiSo)
{
    cout << "Ma hoc phan: " << hocPhan[chiSo].maHocPhan << endl;
    cout << "Ten hoc phan: " << hocPhan[chiSo].tenHocPhan << endl;
    cout << "So tin chi: " << hocPhan[chiSo].soTinChi << endl;
    cout << "Diem trung binh: " << hocPhan[chiSo].diemTrungBinh << endl;
}

void NhapNhieuHocPhan(vector<HocPhan> &hocPhan)
{
    int n;
    do
    {
        cout << "So luong hoc phan can nhap (tu 2 den 10): ";
        cin >> n;
        if (n < 2 || n > 10)
            cout << "N khong duoc nhap chinh xac, hay thu lai!" << endl;
    } while (n < 2 || n > 10);

    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        NhapMotHocPhan(hocPhan);
    }
        
}

void XuatHPTheoDTB(vector<HocPhan> &hocPhan)
{
    for (int i = 0; i < hocPhan.size(); i++)
        if (hocPhan[i].diemTrungBinh > 5.0)
            XuatMotHocPhan(hocPhan, i);
}

int main()
{
    vector<HocPhan> hocPhan;

    NhapMotHocPhan(hocPhan);
    XuatMotHocPhan(hocPhan, 0);
    NhapNhieuHocPhan(hocPhan);
    XuatHPTheoDTB(hocPhan);

    return 0;
}
