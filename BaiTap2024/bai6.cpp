#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> matrix_numbers;
	vector<int> row_numbers = {2, 3, 4, 5};
	vector<int> row_numbers1 = {1, 2, 3, 4};
	
	matrix_numbers.push_back(row_numbers);
	matrix_numbers.push_back(row_numbers1);
	
	for (int i = 0; i < matrix_numbers.size(); i++)
	{
		for (int j = 0; j < matrix_numbers[i].size(); j++)
		{
			cout << matrix_numbers[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
