#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int n;
int a[MAX], l[MAX], lis[MAX];

void Init()
{
    for (int i = 0; i < n; i++)
    {
        l[i] = 1;
        lis[i] = -1;
    }
}

void Dynamic()
{
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && l[i] < l[j] + 1)
            {
                l[i] = l[j] + 1; // Fixed the condition and assignment
            }
    

    // Find the max value in l[]
    int lmax = *max_element(l, l + n);

    // Call Trace LIS function
    TraceLIS(lmax); 
}

void TraceLIS(int lmax)
{
    // Find index with max value in l[]
    int pos_lmax = 0;
    for (int i = 0; i < n; i++)
        if (l[i] > l[pos_lmax])
            pos_lmax = i;

    // Init lis_idx and assign the first value
    int lis_idx = 0;
    lis[0] = a[pos_lmax];
    // Create length (Because pos_lmax is assigned the first value)
    int len = l[pos_lmax] - 1;

    // Trace LIS
    for (int i = pos_lmax - 1; i >= 0; i--) // Fixed the loop condition
    {
        if (l[i] == len && a[i] < lis[lis_idx])
        {
            lis_idx++;
            lis[lis_idx] = a[i];
            len--;
        }
    }

    // Print LIS
    cout << "Longest Increasing Subsequence: ";
    for (int i = 0; i <= lmax - 1; i++)
    {
        if (lis[i] != -1) // Added a check to print valid LIS elements
            cout << lis[i] << " ";
    }
    cout << endl;
}

int main()
{
    cout << "N = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    Init();
    Dynamic();
    return 0;
}
