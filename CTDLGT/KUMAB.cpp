#include <iostream>
using namespace std;

int main()
{
    int sum_beer;
    int beer_consider;
    cin >> sum_beer;
    beer_consider = sum_beer;
    while (beer_consider >= 10) 
    {
        beer_consider -= 10;
        sum_beer += 3;
        beer_consider += 3;
    }
    cout << sum_beer;
    return 0;
}
