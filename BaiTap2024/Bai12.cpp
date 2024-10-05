#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cau_tuyets;

struct nguoi_tuyet 
{
	int a;
	int b;
	int c;
};
vector<nguoi_tuyet> nguoi_tuyets;

void PrintCauTuyet() 
{
	for (const int value : cau_tuyets)
		cout << value << " ";
	cout << endl;
}

int main() 
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		int temp;
		cin >> temp;
		cau_tuyets.push_back(temp);
	}

	sort(cau_tuyets.begin(), cau_tuyets.end());

	PrintCauTuyet();

	while (cau_tuyets.size() >= 3) // Ensure there are at least 3 snowballs to form a snowman
	{	
		nguoi_tuyet new_nguoi_tuyet;
		new_nguoi_tuyet.a = cau_tuyets[0];  // Smallest
		cau_tuyets.erase(cau_tuyets.begin());  // Remove the smallest snowball
		
		// Find the second snowball
		for (int i = 0; i < cau_tuyets.size(); i++) 
		{
			if (cau_tuyets[i] > new_nguoi_tuyet.a) 
			{
				new_nguoi_tuyet.b = cau_tuyets[i];
				cau_tuyets.erase(cau_tuyets.begin() + i); // Remove second snowball
				break;
			}
		}
		
		// Find the third snowball
		for (int i = 0; i < cau_tuyets.size(); i++)
		{
			if (cau_tuyets[i] > new_nguoi_tuyet.b) 
			{
				new_nguoi_tuyet.c = cau_tuyets[i];
				cau_tuyets.erase(cau_tuyets.begin() + i); // Remove third snowball
				break;
			}
		}
		
		// Add the newly formed snowman to the list
		nguoi_tuyets.push_back(new_nguoi_tuyet);
	}
	
	// Output the number of snowmen formed
	cout << nguoi_tuyets.size() << endl;
	
	// Output the snowmen details
	for (const auto &value_nguoi_tuyet : nguoi_tuyets)
	{
		cout << value_nguoi_tuyet.a << " " << value_nguoi_tuyet.b << " " << value_nguoi_tuyet.c << endl;
	}
	return 0;	
}
