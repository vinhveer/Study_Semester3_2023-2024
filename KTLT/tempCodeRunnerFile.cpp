#include <iostream>
#include <algorithm>
#include <functional> 
using namespace std;

#define MAX 100

void Input(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> array[i];
    }
}

void Greedy(int t[], int n, int S)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (S >= t[i]) {
            int num = S / t[i];
            count += num;
            S -= num * t[i];
        }
    }

    cout << "Số lượng lớn nhất có thể mua: " << count << endl;
}

int main()
{
    int n;
    cout << "N = ";
    cin >> n;

    int t[MAX];
    Input(t, n);

    sort(t, t + n, greater<int>()); 
    int S;
    cout << "S = ";
    cin >> S;

    Greedy(t, n, S);

    return 0;
}
