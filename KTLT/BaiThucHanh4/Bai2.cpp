#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100

int n, s, sum, c, cbest;
int t[MAX], x[MAX], tmax[MAX], kq[MAX];

void ReadFile()
{
    ifstream file("bai2.inp");
    if (file.is_open())
    {
        file >> n;
        file >> s;
        for (int i = 1; i <= n; i++)
            file >> t[i];
        file.close();
    }
    else
    {
        cout << "Error!" << endl;
        exit(EXIT_FAILURE);
    }
}

void PrintArray()
{
    cout << "N = " << n << endl;
    cout << "S = " << s << endl;
    cout << "Array value: ";
    for (int i = 1; i <= n; i++)
        cout << t[i] << " ";
    cout << endl;
}

int main()
{
    ReadFile();
    PrintArray();
    return 0;
}