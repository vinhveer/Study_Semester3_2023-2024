#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

#define MAX 30

int t[MAX];
int n;
int tongTien;

void DocFile()
{
    ifstream inputFile("bai2.inp");
    if (inputFile.is_open())
    {
        inputFile >> n;
        inputFile >> tongTien;
        for (int i = 1; i <= n; i++)
                inputFile >> t[i];

        inputFile.close();
    }
    else
    {
        cout << "Error opening input.txt file." << endl;
        exit(EXIT_FAILURE);
    }
}

void XuatMang()
{
    for (int i = 1; i <= n; i++)
        cout << t[i] << " ";
    cout << endl;
}

int main()
{
    DocFile();
    XuatMang();
    return 0;
}
