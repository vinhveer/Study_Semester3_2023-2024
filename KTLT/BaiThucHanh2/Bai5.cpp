#include <iostream>
#include <fstream>
using namespace std;

struct HocPhan
{
    string maHocPhan;
    string tenHocPhan;
    int soTinChi;
};

void Read()
{
    int n;
    ifstream file("HocPhan.txt");
    if (!file)
    {
        cout << "File does not exist. Please try with a different path!" << endl;
        return;
    }

    file >> n;
    for (int i = 0; i < n; i++)
    {
        HocPhan hocPhan;
        file >> hocPhan.maHocPhan;
        file.ignore();
        getline(file, hocPhan.tenHocPhan);
        file >> hocPhan.soTinChi;
        cout << hocPhan.maHocPhan << endl;
        cout << hocPhan.tenHocPhan << endl;
        cout << hocPhan.soTinChi << endl;
    }
    file.close();
}

void Write()
{
    HocPhan hocPhan;

    cout << "Nhap cac thong tin hoc phan can them: " << endl;
    cout << "Ma hoc phan: ";
    cin >> hocPhan.maHocPhan;
    cin.ignore();
    cout << "Ten hoc phan: ";
    getline(cin, hocPhan.tenHocPhan);
    cout << "So tin chi: ";
    cin >> hocPhan.soTinChi;

    ofstream file("HocPhan.txt", ios::app);
    if (!file)
    {
        cout << "File does not exist. Please try with a different path!" << endl;
        return;
    }
    file << hocPhan.maHocPhan << endl;
    file << hocPhan.tenHocPhan << endl;
    file << hocPhan.soTinChi << endl;
    file.close();
}

int main()
{
    Read();
    Write();
    return 0;
}
