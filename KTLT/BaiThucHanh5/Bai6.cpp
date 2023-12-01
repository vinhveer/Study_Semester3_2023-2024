#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void rutTien(int n, int s, int menhGia[], int ketQua[], int& kichThuocKetQua) {
    sort(menhGia, menhGia + n, greater<int>());

    kichThuocKetQua = 0;
    for (int i = 0; i < n; ++i) {
        while (s >= menhGia[i]) {
            ketQua[kichThuocKetQua++] = menhGia[i];
            s -= menhGia[i];
        }
    }
}

void docDuLieu(int& n, int& s, int menhGia[]) {
    ifstream inputFile("bai6_input.txt");

    if (!inputFile) {
        cout << "Lỗi mở file đầu vào.\n";
        return;
    }

    inputFile >> n >> s;

    for (int i = 0; i < n; ++i) {
        inputFile >> menhGia[i];
    }

    inputFile.close();
}

void ghiKetQua(int ketQua[], int kichThuocKetQua) {
    ofstream outputFile("bai6_output.txt");

    if (!outputFile) {
        cout << "Lỗi mở file đầu ra.\n";
        return;
    }

    int tongSoTo = 0;

    if (kichThuocKetQua > 0) {
        outputFile << "Cách trả tiền: ";
        for (int i = 0; i < kichThuocKetQua; ++i) {
            outputFile << ketQua[i] << " ";
            tongSoTo++;
        }
    } else {
        outputFile << "-1";
    }

    outputFile << "\nTổng số tờ: " << tongSoTo;

    outputFile.close();
}


int main() {
    int n, s;
    int menhGia[30];
    int ketQua[30];
    int kichThuocKetQua;

    docDuLieu(n, s, menhGia);
    rutTien(n, s, menhGia, ketQua, kichThuocKetQua);
    ghiKetQua(ketQua, kichThuocKetQua);

    return 0;
}
