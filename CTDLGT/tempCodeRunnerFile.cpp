#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    int cnt = 0;
    double a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    for(int i = 0 ; i < n ; i++){
        if(a[i] >= 8.0 && t >= 500){
            t -= 500;
            ++cnt;
        }
        else if(a[i] >= 7.0 && t >= 320){
            t -= 320;
            ++cnt;
        }
    }
    cout << cnt;

    return 0;
}
    