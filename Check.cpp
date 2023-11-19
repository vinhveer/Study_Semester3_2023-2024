#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
	for (int i = 1; i < argc - 1; i++)
		if (atof(argv[i]) > atof(argv[i + 1]))
		{
			cout << "Day khong tang dan" << endl;
			return 0;
		}
	cout << "Day tang dan" << endl;
	return 0;
}
