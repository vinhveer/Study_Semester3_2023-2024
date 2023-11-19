#include <iostream>
#include <algorithm>
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

bool compare(int a, int b) {
    return a > b;
}

void Greedy(int t[], int n, int S)
{
    int x[MAX] = {0};

    for (int i = 0; i < n; i++)
    {
        x[i] = S / t[i];
        S %= t[i];
    }

    bool isPossible = true;
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1) {
            cout << t[i] << " ";
            isPossible = true;
        }
    }

    if (!isPossible) {
        cout << "Khong co cach rut" << endl;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "N = ";
    cin >> n;

    int t[MAX];
    Input(t, n);

    sort(t, t + n, compare);
    int S;
    cout << "S = ";
    cin >> S;

    Greedy(t, n, S);

    return 0;
}
