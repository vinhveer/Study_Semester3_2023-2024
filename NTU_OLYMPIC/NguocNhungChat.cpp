#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string textRevert(string text)
{
    string text_revert;
    for (int i = text.length() - 1; i >= 0; i--)
    {
        text_revert += text[i];
    }
    return text_revert;
}

bool isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;
    else if (n < 2 || n % 2 == 0)
        return false;
    else
    {
        for (int i = 3; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string text;
        cin >> text;
        text = textRevert(text);

        if (isPrime(stoi(text)))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}