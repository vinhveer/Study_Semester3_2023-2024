#include <iostream>
#include <vector>
using namespace std;

struct DataDisk {
	int before_convert;
	int after_convert;
};

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	vector<DataDisk> disk;
	int n, before_convert, after_convert;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> before_convert;
		cin >> after_convert;
		DataDisk data_disk;
		data_disk.before_convert = before_convert;
		data_disk.after_convert = after_convert;
		disk.push_back(data_disk);
	}

	for (int i = 0; i < n; i++)
	{
		cout << disk[i].before_convert << " " << disk[i].after_convert << endl;
	}
}