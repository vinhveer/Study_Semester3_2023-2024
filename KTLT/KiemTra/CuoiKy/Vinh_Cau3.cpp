#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100

int n, s;
int value[MAX], previous[MAX];

void ReadFile()
{
	ifstream file("Vinh_Cau3.inp");
	file >> n >> s;
	for (int i = 0; i < n; i++)
		file >> value[i];
	
	file.close();
}

void Init()
{
	for (int i = 0; i < n; i++)
		previous[i] = 0;
}

void Dynamic()
{
	int sum_arr;
	int count;
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		Init();
		sum_arr = 0;
		count = 0;
		for (int j = 0; j <= i; j++)
		{
			if (sum_arr + value[j] <= s)
			{
				sum_arr += value[j];
				previous[count] = j;
				count++;
			}
		}
		if (sum_arr == s)
		{
			check = true;
			break;
		}
	}
	
	// TraceLIS
	if (check == true)
	{
		cout << sum_arr << endl;
		for (int i = 0; i < count; i++)
			cout << value[previous[i]] << " ";
	}
	else
	{
		cout << "Khong co ket qua!";
	}
}

int main()
{
	ReadFile();
	Dynamic();
}
