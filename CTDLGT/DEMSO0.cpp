#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int number = 42;

    ostringstream oss;
    oss << number;
    string text = oss.str();
    cout << "Text representation: " << text << endl;
    return 0;
}