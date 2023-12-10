#include <iostream>
using namespace std;

int main()
{
    int n, k, t2;
    cin >> n >> k;
    
    if (n <= k) cout << 10;
    else {
        if ((2 * n) % k == 0) 
            t2 = (2 * n) / k * 5;
        else 
            t2 = (2 * n) / k * 5 + 5;
            
        cout << t2;
    }
        
    return 0;
}