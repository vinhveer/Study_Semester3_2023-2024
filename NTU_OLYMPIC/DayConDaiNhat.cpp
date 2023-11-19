#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> L(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                L[i] = max(L[i], L[j] + 1);
    }

    cout << "Max length: " << *max_element(L.begin(), L.end()) << endl;
    return 0;
}
