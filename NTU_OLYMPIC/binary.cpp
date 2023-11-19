#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    string S;
    cin >> n >> S;
    int S_len = S.length();

    vector<int64_t> prefixCount(n + 1, 0);
    prefixCount[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < S_len; j++) {
            if (i - j >= 0 && S[j] == '1') {
                prefixCount[i] = (prefixCount[i] + prefixCount[i - j - 1]) % mod;
            }
        }
    }

    cout << prefixCount[n] << endl;
    return 0;
}
