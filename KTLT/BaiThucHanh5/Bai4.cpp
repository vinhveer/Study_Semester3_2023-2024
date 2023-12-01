#include <iostream>
#include <fstream>
using namespace std;

#define MAX 30

int n;
int maxc = 10000;
int c[MAX][MAX];
int x[MAX];
int chuaxet[MAX];
int sum = 0;

void ReadFile()
{
    ifstream inputFile("input_bai4.txt");

    if (!inputFile)
    {
        cout << "File does not exist. Please try with a different path!\n";
        return;
    }

    inputFile >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            inputFile >> c[i][j];

    inputFile.close();
}

void PrintMatrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

void Greedy()
{
    int i = 1;
    int xi, tot;
    x[i] = 1;
    chuaxet[i] = 0;
    while (i < n)
    {
        i++;
        tot = maxc;
        for (int j = 2; j <= n; j++)
        {
            if (chuaxet[j] && c[x[i - 1]][j] < tot)
            {
                xi = j;
                tot = c[x[i - 1]][j];
            }
        }
        x[i] = xi;
        chuaxet[xi] = 0;
        sum = sum + c[x[i - 1]][x[i]];
    }
    sum = sum + c[x[n]][1];
}

void PrintResult()
{
    cout << "Path: ";
    for (int i = 1; i <= n; i++)
        cout << x[i] << " -> ";
    cout << x[1] << endl;

    cout << "Total distance: " << sum << endl;
}

void WriteFile()
{
    ofstream outputFile("output_bai4.txt");

    if (!outputFile)
    {
        cout << "Cannot create the output file. Please check the permissions or try a different path!\n";
        return;
    }

    outputFile << "Path: ";
    for (int i = 1; i <= n; i++)
        outputFile << x[i] << " -> ";
    outputFile << x[1] << endl;

    outputFile << "Total distance: " << sum << endl;

    outputFile.close();
}

int main()
{
    ReadFile();
    
    for (int i = 2; i <= n; i++)
        chuaxet[i] = 1;
    
    PrintMatrix();
    Greedy();
    PrintResult();
    WriteFile();

    return 0;
}