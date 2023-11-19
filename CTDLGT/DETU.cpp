#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str;
  cin >> str;
  int count = 0;
  if (str[0] != '.')
    count++;

  for (int i = 0; i < str.length() - 1; i++) {
    if (str[i] == '.' && (str[i + 1] != '.')) {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
