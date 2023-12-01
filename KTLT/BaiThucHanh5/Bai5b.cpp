#include <iostream>
using namespace std;

int SumOfSquares(int n)
{
    if (n == 1)
        return 1;

    int smallerSum = SumOfSquares(n - 1);

    return smallerSum + n * n;
}

int main()
{
    int n;
    cin >> n;
    int result = SumOfSquares(n);
    cout << "S(" << n << ") = " << result << endl;
    return 0;
}
