#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAX 100

void ReadFile(int &n, int a[])
{
    ifstream file("Bai4.inp");
    file >> n;
    for (int i = 0; i < n; i++)
        file >> a[i];
}

void Greedy(int n, int a[], int time)
{
    sort(a, a + n);
    int time_test = 0;
    int pos_test = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
        if (time_test <= time && time_test + a[i] <= time)
        {
            time_test += a[i];
            pos_test = i;
            count++;
        }
        else
            break;
    
    cout << count << " " << time_test << endl;
    for (int i = 0; i <= pos_test; i++)
        cout << a[i] << " ";
}

int main()
{
    int n;
    int time = 40;
    int a[MAX];
    ReadFile(n, a);
    Greedy(n, a, time);
}