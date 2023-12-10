#include <iostream>
using namespace std;

double Percent(double number) {
    double percent = (number * 10) / 100;
    long long int percent_int = (number * 10) / 100;
    if (percent - percent_int < 0.5) {
        return percent_int;
    } else {
        return percent_int + 1;
    }
}

int main() {
    double n;
    double m;
    cin >> n >> m;
    int year = 0;
    while (n < m) {
        n += Percent(n);
        year++;
    }
    cout << year;
    return 0;
}