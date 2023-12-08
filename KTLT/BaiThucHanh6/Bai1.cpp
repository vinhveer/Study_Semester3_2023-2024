#include <iostream>
using namespace std;
#define MAX 100

int a[] = {12, 1, 4, 7, 5, 8, 7, 9, 16};
int n;
int l[MAX];
int t[MAX];
int lmax;

void Init()
{
    n = sizeof(a) / sizeof(a[0]);
    l[0] = 0;
    for (int i = 0; i < n; i++)
        t[i] = -1;
}

void Dynamic()
{
    for (int i = 0; i < n; i++)
    {
        lmax = 0;
        for (int j = 0; j < i; j++)
            if (a[j] <= a[i] && lmax < l[j])
            {
                lmax = l[j];
                t[i] = j;
            }
        l[i] = lmax + 1;
    }
}

void Track()
{
    int max = l[0], p = -1;
    for (int i = 1; i < n; i++)
    {
        if (max < l[i])
        {
            max = l[i];
            p = i;
        }
    }
    cout << "Do dai day tang dai nhat la " << max << endl;
    cout << "Vi tri cac phan tu: ";
    while (p >= 0)
    {
        cout << p << ":" << a[p] << " ";
        p = t[p];
    }
    cout << endl;
}

int main()
{
    Init();
    Dynamic();
    for (int i = 0; i < n; i++)
        cout << l[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << t[i] << " ";
    cout << endl;
    
    Track();

    return 0;
}
