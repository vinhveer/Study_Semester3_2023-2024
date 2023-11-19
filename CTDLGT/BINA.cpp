#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0; // Trường hợp đặc biệt: n = 0
    } else {
        string binaryRepresentation = ""; // Chuỗi để lưu biểu diễn nhị phân

        while (n > 0) {
            int remainder = n % 2; // Lấy phần dư khi chia cho 2
            binaryRepresentation = to_string(remainder) + binaryRepresentation; // Thêm phần dư vào đầu chuỗi
            n /= 2; // Chia n cho 2
        }

        cout << binaryRepresentation;
    }

    return 0;
}
