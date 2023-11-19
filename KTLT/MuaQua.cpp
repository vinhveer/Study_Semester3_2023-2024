#include <iostream>
#include <algorithm>
#include <functional> // Thêm thư viện này để sử dụng std::greater
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

void Greedy(int a[], int n, int S)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (S >= a[i]) {
            S -= a[i];
            count++;
        } else {
            break;
        }
    }

    cout << "Số lượng lớn nhất có thể mua: " << count << endl;
}

int main()
{
    int n;
    cout << "N = ";
    cin >> n;

    int a[MAX];
    Input(a, n);

    sort(a, a + n, less<int>());

    int S;
    cout << "S = ";
    cin >> S;

    Greedy(a, n, S);

    return 0;
}
