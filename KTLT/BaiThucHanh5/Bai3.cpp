#include <iostream>
#define MAX 50
#define SWAP(a, b, c) \
    {                 \
        c = a;        \
        a = b;        \
        b = c;        \
    }
using namespace std;

float v[MAX];
float w[MAX];
int n;
float p[MAX];
int x[MAX];
float T, M = 9;

void Init()
{
    T = M;
    for (int i = 0; i < n; i++)
    {
        p[i] = v[i] / w[i];
    }
    float temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i] < p[j])
            {
                SWAP(p[i], p[j], temp);
                SWAP(v[i], v[j], temp);
                SWAP(w[i], w[j], temp);
            }
        }
    }
}

void Print()
{
    cout << "Trong luong tui dung do vat: " << M - T << endl;
    T = 0;
    float k = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] != 0)
        {
            cout << "x: " << x[i] << " "
                 << "v: " << v[i] << "| "
                 << "w: " << w[i] << endl;
            T = T + x[i] * v[i];
            k = k + x[i] * w[i];
        }
    }
    cout << "Gia tri lon nhat la " << T << " "
         << "voi tong trong luong la " << k;
}

void Greedy()
{
    int i = 0;
    while (T > 0 && i < n)
    {
        if (T >= w[i])
        {
            x[i]++;
            T -= w[i];
        }
        else
            i++;
    }
}

int main()
{
    cout << "N = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "v[" << i << "] = ";
        cin >> v[i];
        cout << "w[" << i << "] = ";
        cin >> w[i];
    }
    Init();
    Greedy();
    Print();
    return 0;
}
