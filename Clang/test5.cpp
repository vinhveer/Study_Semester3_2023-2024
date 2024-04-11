#include <stdio.h>
#include <math.h>
void nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
}
void in(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void ss(int a[], int n)
{
	// can n-1 buoc dua phan tu nho nhat ra dau day
	for (int i = 0; i < n - 1; i++)
	{
		// duyet thang o sau
		int min_pos = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
			{
				min_pos = j;
			}
		// sau vong for nay ket thuc ta da co vi tri cua phan tu nho ta dua no ra dau
		// bang cach swap a[min_pos] voi a[i]
		int tmp = a[min_pos];
		a[min_pos] = a[i];
		a[i] = tmp;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	nhap(a, n);
	ss(a, n);
	in(a, n);
}
