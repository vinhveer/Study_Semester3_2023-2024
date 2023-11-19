#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint> // Thêm thư viện này
using namespace std;

// Hàm kiểm tra hai số nguyên có phải là số nguyên tố cùng nhau hay không
bool coprime(int64_t a, int64_t b) { // Thay thế int bằng int64_t
    // Sử dụng thuật toán Euclid để tính ước chung lớn nhất của a và b
    while (b != 0) {
        int64_t r = a % b; // Thay thế int bằng int64_t
        a = b;
        b = r;
    }
    // Hai số nguyên tố cùng nhau khi ước chung lớn nhất của chúng là 1
    return a == 1;
}

// Hàm tính số cách truyền thông tin từ ai đến aj qua k + 1 người
int64_t count_ways(vector<int64_t>& A, int64_t ai, int64_t aj, int64_t k) { // Thay thế int bằng int64_t và vector<int> bằng vector<int64_t>
    // Sắp xếp danh sách số nhà theo thứ tự tăng dần
    sort(A.begin(), A.end());
    // Tạo một ma trận dp[n][k] để lưu kết quả của các bài toán con
    // dp[i][j] là số cách truyền thông tin từ ai đến A[i] qua j + 1 người
    int n = A.size();
    vector<vector<int64_t>> dp(n, vector<int64_t>(k, 0)); // Thay thế int bằng int64_t
    // Khởi tạo giá trị ban đầu cho ma trận dp
    // Nếu ai và A[i] là số nguyên tố cùng nhau, có một cách truyền thông tin qua 1 người
    for (int i = 0; i < n; i++) {
        if (coprime(ai, A[i])) {
            dp[i][0] = 1;
        }
    }
    // Cập nhật giá trị cho ma trận dp theo công thức quy hoạch động
    // dp[i][j] = tổng(dp[t][j - 1]) với mọi t < i sao cho A[t] và A[i] là số nguyên tố cùng nhau
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < k; j++) {
            for (int t = 0; t < i; t++) {
                if (coprime(A[t], A[i])) {
                    dp[i][j] += dp[t][j - 1];
                    dp[i][j] %= 2023; // Lấy phần dư theo yêu cầu đề bài
                }
            }
        }
    }
    // Tìm vị trí của aj trong danh sách A
    int pos = lower_bound(A.begin(), A.end(), aj) - A.begin();
    // Trả về kết quả là dp[pos][k - 1]
    return dp[pos][k - 1];
}

int main() {
    // Nhập vào số thành viên n
    int64_t n; // Thay thế int bằng int64_t
    cin >> n;
    // Nhập vào danh sách số nhà A
    vector<int64_t> A(n); // Thay thế vector<int> bằng vector<int64_t>
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // Nhập vào số truy vấn Q
    int64_t Q; // Thay thế int bằng int64_t
    cin >> Q;
    // Xử lý từng truy vấn
    for (int i = 0; i < Q; i++) {
        // Nhập vào ai, aj, k
        int64_t ai, aj, k; // Thay thế int bằng int64_t
        cin >> ai >> aj >> k;
        // Tính và in ra số cách truyền thông tin
        int64_t ans = count_ways(A, ai, aj, k); // Thay thế int bằng int64_t
        cout << ans << endl;
    }
    return 0;
}
