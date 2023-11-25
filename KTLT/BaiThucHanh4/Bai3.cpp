#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

int n, s;
int t[MAX], x[MAX];
int count = 1;

void ReadFile()
{
    ifstream file("bai3_input.txt");
    if (!file.is_open())
        printf("Loi file");
    else
    {
        file >> n;
        file >> s;
        for (int i = 1; i <= n; i++)
            file >> t[i];
        file.close();
    }
}

void PrintArray()
{
    cout << n << " " << s << endl;
    for (int i = 1; i <= n; i++)
        cout << t[i] << " ";
    cout << endl;
}

void PrintResult()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += x[i] * t[i];

    if (sum == s)
    {
        cout <<"Cach " << count++ << ": ";
        for (int i = 1; i <= n; i++)
            if (x[i])
                cout << "(" << i << ")" << t[i] << "\t";
        cout << endl;
    }
}

void Try(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n)
            PrintResult();
        else
            Try(i + 1);
    }
}

int main()
{
    ReadFile();
    PrintArray();
    Try(1);
    return 0;
}