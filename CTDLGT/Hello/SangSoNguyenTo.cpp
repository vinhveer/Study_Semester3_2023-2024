#include <iostream>
#include <vector>
using namespace std;

void Eratosthenes(vector<int>& result, int n)
{
    vector<int> array;
    for (int i = 2; i <= n; i++)
    {
        array.push_back(i);
    }

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] != 0)
        {
            for (int j = i + 1; j < array.size(); j++)
            {
                if (array[j] % array[i] == 0)
                    array[j] = 0;
            }
        }
    }

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] != 0)
        {
            result.push_back(array[i]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> result;
    Eratosthenes(result, n);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
