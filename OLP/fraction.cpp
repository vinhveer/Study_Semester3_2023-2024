#include <iostream>
#include <math.h>
using namespace std;

int UocSoNhoNhat(int number)
{
    for (int i = 2; i <= number; i++)
    {
        if ((number % i) == 0)
        {
            return i;
        }
    }
    return -1;
}

double Sum(int n)
{
    double sum = 0;
    int i, temp;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        sum += temp;
    }
    return sum;
}

double UCLN(double a, double b)
{
    if (b == 0)
        return a;
    else
        return UCLN(b, fmod(a, b));
}

int Factor(int n)
{
    if (n == 1)
        return 0;
    else
    {
        int uocSoNhoNhat = UocSoNhoNhat(n);
        if (uocSoNhoNhat == 2 || uocSoNhoNhat == 5)
            return Factor(n/uocSoNhoNhat);
        else
            return 1;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T, count;
    cin >> T;

    int n;

    for (count = 0; count < T; count++)
    {
        cin >> n;
        double sum_a = 0, sum_b = 0;
        double fraction;
        sum_a = Sum(n);
        sum_b = Sum(n);
        double ucln = UCLN(sum_a, sum_b);
        sum_a /= ucln;
        sum_b /= ucln;
        fraction = sum_a / sum_b;
        if (Factor(sum_b) == 1)
            cout << "repeating" << endl;
        else
            cout << "finite" << endl;
    }  

    return 0;
}
