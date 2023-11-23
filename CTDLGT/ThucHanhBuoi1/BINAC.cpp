#include <iostream>
#include <stack>

using namespace std;

void Print(int n)
{
    stack<int> binaryStack;

    if (n == 0)
    {
        cout << "0" << endl;
        return;
    }

    while (n > 0)
    {
        int bit = n % 2;
        binaryStack.push(bit);
        n = n / 2;
    }

    while (!binaryStack.empty())
    {
        cout << binaryStack.top();
        binaryStack.pop();
    }

    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    Print(n);

    return 0;
}
