#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100

int n, s;
int t[MAX], x[MAX], tmax[MAX], kq[MAX];
int sum, c, cbest;
bool kt = false;

void ReadFile()
{
    ifstream file("bai2_input.txt");
    if (!file.is_open())
        cout << "Loi file";
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

void Update()
{
    if (sum == s && c < cbest)
    {
        cbest = c;
        kt = true;
        for (int i = 1; i <= n; i++)
            kq[i] = x[i];
    }
}

void PrintResult()
{
    cout << "Finish caculate. Open file 'bai2_output.txt' to see results!" << endl;
    ofstream file("bai2_output.txt");
    if (file.is_open())
    {
        if (cbest < n + 1)
        {
            file << "Cach tra tien cua ATM: ";
            for (int i = 1; i <= n; i++)
                if (kq[i])
                    file << t[i] << " ";
            file << endl;
            file << "Tong so to la: " << cbest;
        }
        else
            file << "Khong co phuong an tra tien";
    }
    else
        cout << "Loi file";
}

void ATM(int i)
{
    if (c + (s - sum) / tmax[i] < cbest)
        for (int j = 0; j <= 1; j++)
        {
            x[i] = j;
            sum += x[i] * t[i];
            c += j;
            if (i == n)
                Update();
            else if (sum < s)
                ATM(i + 1);
            sum -= x[i] * t[i];
            c -= j;
        }
}

int main()
{
    ReadFile();
    PrintArray();
    tmax[n] = t[n];
    for (int i = n - 1; i >= 1; i--)
    {
        tmax[i] = tmax[i + 1];
        if (tmax[i] < t[i])
            tmax[i] = t[i];
    }

    sum = 0;
    c = 0;
    cbest = n + 1;
    ATM(1);
    PrintResult();

    return 0;
}
