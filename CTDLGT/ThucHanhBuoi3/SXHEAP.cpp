#include <iostream>
using namespace std;
#define MAX 20

void AdjustHeap(int a[MAX], int n, int i)
{
    int k = i, p = 2 * i + 1, r = 2 * i + 2;
    if (p < n && a[p] > a[k])
        k = p;
    if (r < n && a[r] > a[k])
        k = r;
    if (k != i)
    {
        swap(a[i], a[k]);
        AdjustHeap(a, n, k);
    }
}

void BuildHeap(int a[MAX], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        AdjustHeap(a, n, i);
}

void print(int a[MAX], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void HeapSort(int a[MAX], int n)
{
    BuildHeap(a, n);
    int hsize = n;
    print(a, n);
    while (hsize > 1)
    {
        swap(a[0], a[hsize - 1]);
        hsize--;
        AdjustHeap(a, hsize, 0);
        print(a, hsize);
    }
}

int main()
{
    int a[MAX], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    HeapSort(a, n);

    return 0;
}
