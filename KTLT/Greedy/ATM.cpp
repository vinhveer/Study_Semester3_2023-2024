#include <iostream>
using namespace std;

#define MAX 100

int S, n;
int a[MAX];
int x[MAX];

void SapXep()
{
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[index])
                index = j;
        }
        swap(a[index], a[i]);
        cout << endl;
    }
}

void KhoiTao()
{
    cout << "Nhap so luong menh gia: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
        x[i] = 0;
    }
    SapXep();
}

void In()
{
    for (int i = 0; i < n; i++)
        cout << x[i] << ":" << a[i] << " ";
    cout << endl;
}

void ThamLam()
{
    int i = 0;
    int c = 0;
    while (S > 0 && i < n)
    {
        if (S >= a[i])
        {
            x[i]++;
            S -= a[i];
            c++;
        }
        else
            i++;
    }
    if (S == 0)
        In();
}


int main()
{
    cin >> S;
    KhoiTao();
    ThamLam();
}