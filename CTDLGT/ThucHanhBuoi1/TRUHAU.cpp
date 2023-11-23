#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int getPriority(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> operators;
    string postfix = "";

    for (char c : infix)
    {
        if (isalpha(c))
        {
            postfix += c;
            postfix += ' '; // Thêm dấu cách sau mỗi giá trị
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                postfix += ' '; // Thêm dấu cách sau mỗi giá trị
                operators.pop();
            }
            operators.pop();
        }
        else if (isOperator(c))
        {
            while (!operators.empty() && getPriority(c) <= getPriority(operators.top()))
            {
                postfix += operators.top();
                postfix += ' '; // Thêm dấu cách sau mỗi giá trị
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty())
    {
        postfix += operators.top();
        postfix += ' '; // Thêm dấu cách sau mỗi giá trị
        operators.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    getline(cin, infix);

    string postfix = infixToPostfix(infix);

    cout << postfix << endl;

    return 0;
}
