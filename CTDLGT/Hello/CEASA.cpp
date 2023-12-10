#include <iostream>
#include <string>
using namespace std;

int main() {
    string encoded_message;
    int k;
    cin >> encoded_message;
    cin >> k;

    // Khôi phục bản tin ban đầu
    for (char& c : encoded_message) {
        if (isalpha(c)) { // Chỉ xử lý các ký tự chữ cái
            char base = (isupper(c)) ? 'A' : 'a'; // Xác định ký tự cơ sở (A hoặc a)
            c = static_cast<char>((c - base - k + 26) % 26 + base);
        }
    }

    cout << encoded_message << endl;
    return 0;
}
