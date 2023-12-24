#include <iostream>
#include <algorithm>
using namespace std;

int n;
int value[100], length[100],lis[100];

void Init()
{
    for (int i = 0; i < n; i++)
    {
        length[i] = 1;
        lis[i] = -1;
    }
}

void Dynamic()
{
    int lis_index = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (value[i] > value[j] && length[i] < length[j] + 1)
            {
                length[i] = length[j] + 1;
            }
        }
    }
    int lmax = *max_element(length, length + n);
    cout << lmax;
    for (int i = 0; i <= lis_index; i++)
        cout << value[lis[i]] << " " << endl;
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> value[i];

    Init();
    Dynamic();
}