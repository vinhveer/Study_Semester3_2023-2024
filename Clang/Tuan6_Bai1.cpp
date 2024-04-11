#include <bits/stdc++.h>
using namespace std;

void Input(int *n, int *a)
{
    for (int i = 0; i < *n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> *(a + i);
    }
}

void Output(int *n, int *a)
{
    printf("The values in the array are: ");
    for (int i = 0; i < *n; i++)
        cout << *(a + i) << " ";
    cout << endl;
}

void Swap(int *value1, int *value)
{
    int temp = *value1;
    *value1 = *value2;
    *value2 = temp;
}

void SortAscending(int *n, int *a)
{
    for (int i = 0; i < *n; i++)
        for (int j = i + 1; j < *n; j++)
            if (*(a + i) > *(a + j))
                Swap((a + i), (a + j));
}

void ReplaceElement(int *n, int *a)
{
    int position;
    int value;
    do
    {
        cout << "Enter the position to be replace: ";
        cin >> position;
        if (position < 0 || position >= *n)
            cout << "Error! Please try input!" << endl;
    } while (position < 0 || position >= *n);
    cout << "Enter the value to be replace: ";
    cin >> value;
    *(a + position) = value;
    cout << "Successfully replace!" << endl;
}

void DynamicAllocation(int **a, int n)
{
    *a = (int *)realloc(*a, n * sizeof(int));
}

void InsertElement(int *n, int **a)
{
    int value;
    (*n)++;
    cout << *n << endl;
    DynamicAllocation(a, *n);
    cout << "Enter the value: ";
    cin >> value;
    *(*a + *n - 1) = value;
    SortAscending(n, *a);
}

void RemoveValue(int *n, int **a)
{
    int position;
    do
    {
        cout << "Enter the position to be remove: ";
        cin >> position;
        if (position < 0 || position >= *n)
            cout << "Error! Please try input!" << endl;
    } while (position < 0 || position >= *n);
    for (int i = position; i < (*n - 1); i++)
        *(*a + i) = *(*a + i + 1);
    DynamicAllocation(a, *n - 1);
    (*n)--;
    cout << "Successfully remove!" << endl;
}

int CheckPrime(int number)
{
    if (number == 2)
    {
        return 0;
    }
    if (number < 2 || number % 2 == 0)
    {
        return 1;
    }
    for (int i = 3; i <= sqrt(number); i += 2)
    {
        if (number % i == 0)
        {
            return 1;
        }
    }
    return 0;
}

void PrintPrime(int *n, int *a)
{
    printf("The prime numbers in the array are: ");
    for (int i = 0; i < *n; i++)
        if (CheckPrime(*(a + i)) == 0)
            cout << *(a + i) << " ";
    cout << endl;
}

int main()
{
    int n;
    int *a;
    cout << "Enter the number of elements: ";
    cin >> n;
    a = (int *)malloc(n * sizeof(int));
    Input(&n, a);
    Output(&n, a);
    SortAscending(&n, a);
    Output(&n, a);
    ReplaceElement(&n, a);
    Output(&n, a);
    InsertElement(&n, &a);
    Output(&n, a);
    RemoveValue(&n, &a);
    Output(&n, a);
    PrintPrime(&n, a);
    free(a);
    return 0;
}