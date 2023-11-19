#include <iostream>
#include <vector>

using namespace std;

vector<int> calculateFactorial(int n) {
    vector<int> result;
    result.push_back(1);
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < result.size(); j++) {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }

        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    return result;
}

int countTrailingZeros(const vector<int>& num) {
    int count = 0;
    for (int i = 0; i <= num.size(); i++) {
        if (num[i] == 0) {
            count++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> result = calculateFactorial(n);
    int trailingZeros = countTrailingZeros(result);

    cout << trailingZeros << endl;

    return 0;
}
