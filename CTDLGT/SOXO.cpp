#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long even_count = 0;  
    long long odd_count = 0; 
    long long even_sum = 0; 
    long long odd_sum = 0; 

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        if (num % 2 == 0) {
            even_count++;
            even_sum += num;
        } else {
            odd_count++;
            odd_sum += num;
        }
    }

    long long result = even_count * odd_count;
    if ((even_sum + odd_sum) % 2 == 0) {
        result += even_count * (even_count - 1) / 2;
        result += odd_count * (odd_count - 1) / 2;
    }

    cout << result << endl;

    return 0;
}
