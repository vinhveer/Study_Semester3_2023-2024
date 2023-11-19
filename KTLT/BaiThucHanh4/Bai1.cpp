#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

#define MAX 30

int n;
int c[MAX][MAX];
int x[MAX];
int chuaXet[MAX];
int tongChiPhi[MAX];

void DocFile()
{
    ifstream inputFile("input.txt");
    if (inputFile.is_open())
    {
        inputFile >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                inputFile >> c[i][j];

        inputFile.close();
    }
    else
    {
        cout << "Error opening input.txt file." << endl;
        exit(EXIT_FAILURE);
    }
}

void XuatMaTran()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

void InKetQua()
{
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " -> ";
        s += c[x[i - 1]][x[i]];
    }
    s += c[x[n - 1]][1];
    cout << x[1] << " ";
    cout << "Cost: " << s << endl;
}

void TP(int i)
{
    for (int j = 2; j <= n; j++)
        if (chuaXet[j] == 0)
        {
            x[i] = j;
            chuaXet[j] = 1;
            if (i == n)
                InKetQua();
            else
                TP(i + 1);
            chuaXet[j] = 0;
        }
}

void GhiFile()
{
    ofstream outputFile("output.txt");
    if (outputFile.is_open())
    {
        InKetQua(); // Write the result to the file
        outputFile.close();
    }
    else
    {
        cout << "Error opening output.txt file." << endl;
        exit(EXIT_FAILURE);
    }
}

int main()
{
    // Khoi tao chua xet thanh phan la 0
    for (int i = 1; i <= n; i++)
        chuaXet[i] = 0;

    x[1] = 1;
    DocFile();
    XuatMaTran();
    GhiFile();
    TP(2);

    return 0;
}
