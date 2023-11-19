#include <iostream>
using namespace std;

void ReadFile(int &n, float a[])
{
	FILE *fp = fopen("input.txt", "r+");
	if (fp == NULL)
		cout << "File khong ton tai!";
	
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++)
		fscanf(fp, "%f", &a[i]);
	
	fclose(fp);
}

double BestScore(int n, float a[], float max)
{
	if (n == -1)
		return max;
	if (a[n] > max)
		max = a[n];
	return BestScore(n - 1, a, max);
}

void WriteFile(int n, float a[])
{
	FILE *fp = fopen("output.txt", "w+");
	if (fp == NULL)
		cout << "File khong ton tai!";
	
	float max = a[0];
	fprintf(fp, "Mark: %0.2f", BestScore(n - 1, a, max));
	
	fclose(fp);
}

int main()
{	
	float a[50];
	int n;
	
	ReadFile(n, a);
	WriteFile(n, a);
	
	return 0;
}
