#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	float n, x_cow, y_cow;
	cin >> n;
	cin >> x_cow;
	cin >> y_cow;

	float x_temp, y_temp, r_temp;
	float distance_grass = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x_temp;
		cin >> y_temp;
		cin >> r_temp;
		distance_grass = sqrt(((x_temp - x_cow) * (x_temp - x_cow)) + ((y_temp - y_cow) * (y_temp - y_cow))) - r_temp;
		cout << distance_grass << endl; 
	}
	return 0;	
}