#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAX4NUM(a, b, c, d) \
        ((a) > (b) && (a) > (c) && (a) > (d)) ? (a) : \
        ((b) > (a) && (b) > (c) && (b) > (d)) ? (b) : \
        ((c) > (a) && (c) > (b) && (c) > (d)) ? (c) : (d) \

int main()
{
    cout << MAX(2, 3) << endl;
    cout << MAX4NUM(2, 3, 5, 4) << endl;
    return 0;
}
