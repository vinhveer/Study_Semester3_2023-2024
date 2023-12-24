#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAX 100

int n, v;
int s[MAX];

void ReadFile()
{
	ifstream file("Vinh_Cau2.inp");
	file >> n >> v;
	for (int i = 0; i < n; i++)
		file >> s[i];
	
	file.close();
}

void Greedy()
{
	int count = 0;
	int ketqua[MAX];
	int sum = 0;
	
	sort(s, s + n, greater<int>());
	for (int i = 0; i < n; i++)
		if (s[i] + sum <= v)
		{
			ketqua[count] = s[i];
			sum += s[i];
			count++;
		}
	
	ofstream file("Vinh_Cau2.out");
	file << count << endl;
	for (int i = 0; i < count; i++)
		file << s[i] << " ";
}

int main()
{
	ReadFile();
	Greedy();
}
