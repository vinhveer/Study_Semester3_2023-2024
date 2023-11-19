#include <iostream>
#include <map>
#include <string>
using namespace std;

int calculateTypingTime(string message) {
    int time = 0;
    map<char, int> charToKeypress = {
        {'A', 2}, {'B', 3}, {'C', 4},
        {'D', 2}, {'E', 3}, {'F', 4},
        {'G', 2}, {'H', 3}, {'I', 4},
        {'J', 2}, {'K', 3}, {'L', 4},
        {'M', 2}, {'N', 3}, {'O', 4},
        {'P', 2}, {'Q', 3}, {'R', 4}, {'S', 5},
        {'T', 2}, {'U', 3}, {'V', 4},
        {'W', 2}, {'X', 3}, {'Y', 4}, {'Z', 5},
        {'1', 1}, {'2', 1}, {'3', 1}, {'4', 1}, 
        {'5', 1}, {'6', 1}, {'7', 1}, {'8', 1},
        {'9', 1}, {'0', 1}
    };

    for (int i = 0; i < message.length(); i++)
    {
        int keypress = charToKeypress[message[i]];
        time += keypress;
    }
    return time;



}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    string message;
    cin >> message;

    cout << calculateTypingTime(message);

    return 0;
}