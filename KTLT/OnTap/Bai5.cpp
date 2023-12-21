#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

int n;
int a[MAX], length[MAX], previous[MAX];

void TraceLIS(int idx)
{
    int lis[MAX];
    int lis_length = *max_element(length, length + n);
    int current_idx = idx;
    for (int i = lis_length - 1; i >= 0; --i)
    {
        lis[i] = a[current_idx];
        current_idx = previous[current_idx];
    }

    cout << "Dãy con tăng dài nhất: ";
    for (int i = 0; i < lis_length; ++i)
    {
        cout << lis[i] << " ";
    }
    cout << endl;
}

void Solve()
{
    for (int i = 0; i < n; i++)
    {
        length[i] = 1;
        previous[i] = -1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && length[i] < length[j] + 1)
            {
                length[i] = length[j] + 1;
                previous[i] = j;
            }
        }
    }

    int max_length = *max_element(length, length + n);
    cout << "Độ dài của dãy con tăng dài nhất: " << max_length << endl;

    // Truy vết dãy con tăng dài nhất bằng cách chuyển index kết thúc dãy con tăng dài nhất
    for (int i = n - 1; i >= 0; --i)
    {
        if (length[i] == max_length)
        {
            TraceLIS(i);
            break;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Solve();
}