#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100

int c[MAX][MAX];
int x[MAX + 1];
int notEvaluate[MAX];
int n;

bool ReadFile()
{
    ifstream file("bai1_input.txt");
    if (!file.is_open())
    {
        cout << "Error opening file\n";
        return false;
    }
    else
    {
        file >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                file >> c[i][j];
        file.close();
        return true;
    }
}

void PrintMatrix()
{
    cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

void PrintResult()
{
    int s = 0;
    cout << "City1 -> ";
    for (int i = 2; i <= n; i++)
    {
        cout << "City " << x[i] << " -> ";
        s += c[x[i - 1]][x[i]];
    }
    s += c[x[n]][1];
    cout << "City1 ; ";
    cout << "Total cost is: " << s << endl;
}

void City(int i)
{
    for (int j = 2; j <= n; j++)
        if (notEvaluate[j] == 0)
        {
            x[i] = j;
            notEvaluate[j] = 1;
            if (i == n)
                PrintResult();
            else
                City(i + 1);
            notEvaluate[j] = 0;
        }
}

int main()
{
    for (int i = 2; i <= n; i++)
        notEvaluate[i] = 0;
    x[1] = 1;

    if (ReadFile())
    {
        PrintMatrix();
        City(2);
    }

    return 0;
}
