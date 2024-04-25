#include <iostream>
using namespace std;

void PrintArray(int a[], int size, int Index)
{
    for (int i = 0; i < size; ++i)
    {
        if (i == Index)
        {
            cout << "[" << a[i] << "] ";
        }
        else
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
}

void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            --j;
        }

        a[j + 1] = key;
        PrintArray(a, n, j + 1);
    }
}

int main()
{
    int n;
    cin >> n;

    int a[20];

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    InsertionSort(a, n);

    return 0;
}
