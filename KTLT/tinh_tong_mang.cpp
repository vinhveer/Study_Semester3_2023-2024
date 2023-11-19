#include <iostream>
using namespace std;

#define MAX 100

void InputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

int SumArray(int a[], int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return a[0];
    else
    {
        int mid = n / 2;
        int left_sum = SumArray(a, mid);
        int right_sum = SumArray(a + mid, n - mid);
        return left_sum + right_sum;
    }
}

int main()
{
    int a[MAX];
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    InputArray(a, n);
    SumArray(a, n);

    cout << "Sum = " << SumArray(a, n);
    return 0;
}