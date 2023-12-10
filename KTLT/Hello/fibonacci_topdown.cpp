#include <iostream>

long long fibonacci_top_down(int n) 
{
    if (n <= 1) 
        return n;
    
    return fibonacci_top_down(n - 1) + fibonacci_top_down(n - 2);
}

int main()
{
    int n;
    std::cout << "Nhập n: ";
    std::cin >> n;
    
    long long result = fibonacci_top_down(n);
    
    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;
    
    return 0;
}
