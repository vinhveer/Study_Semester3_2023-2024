#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int64_t L, R, A, K;
    cin >> L >> R >> A >> K;

    int64_t count = 0;
    for (int S = L; S <= R; S++)
        if (((A * S) % K) == 0)
            count++;

    cout << count;
    return 0;
}