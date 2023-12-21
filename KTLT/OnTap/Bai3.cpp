#include <iostream>
#include <fstream>
using namespace std;

#define MAX 50

void ReadFile(int &n, float a[])
{
    ifstream file("Bai3.inp");
    file >> n;
    for (int i = 0; i < n; i++)
        file >> a[i];
    file.close();
}

float SumPositive(int n, float a[])
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > 0)
            sum += a[i];

    return sum;
}

int main()
{
    int n;
    float a[MAX];
    ReadFile(n, a);
    cout << "Sum = " << SumPositive(n, a) << endl;
    return 0;
}
