#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX 50

int RandomNumber()
{
    return rand() % 1001;
}

void InitializeValue(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = RandomNumber();
}

void OutputMatrix(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

bool CheckPrime(int n)
{
	if (n == 2 || n = 3)
		return true;
	else if (n < 2 || n % 2 == 0)
		return false;
	else
	{
		for (int i = 3; i <= sqrt(n); i += 2)
			if (n % i == 0)
			{
				return false;
				break;
			}
		return true;
	}
}

void FindPrimeValue(int a[MAX][MAX], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (CheckPrime(a[i][j]) == 1)
				count++;

	cout << count << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (CheckPrime(a[i][j]) == 1)
				cout << a[i][j] << " ";
}

int main()
{
    srand(time(NULL));

    int a[MAX][MAX];
    int n;

    cout << "Nhap so phan tu (nxn): ";
    cin >> n;

    InitializeValue(a, n);
   
#ifndef ONLINE_JUDGE
	freopen("Lab2_2.dat", "w", stdout);
#endif

	OutputMatrix(a, n);
	FindPrimeValue(a, n);
	
    return 0;
}
