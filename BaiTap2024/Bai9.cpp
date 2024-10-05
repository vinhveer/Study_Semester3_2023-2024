#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxMatrixValue(vector<vector<int>> &matrix)
{
	int max_value = matrix[0][0];
	for (const auto &row : matrix)
		for (int value : row)
			max_value = max(max_value, value);
			
	return max_value;
}

int main()
{
	vector<vector<int>> number_matrix = {{1, 2, 3, 4}, {1, 2, 3}, {1, 2, 5, 3, 4}};
	cout << maxMatrixValue(number_matrix);
	return 0;
}
