#include <iostream>
#include <vector>
using namespace std;

int SumMatrix(vector<vector<int>> &matrix)
{
	int result = 0;
	for (const auto &number_row : matrix)
		for (int value : number_row)
			result += value;
	
	return result;
}

int main()
{
	vector<vector<int>> number_matrix = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
	cout << SumMatrix(number_matrix);
	return 0;
}
