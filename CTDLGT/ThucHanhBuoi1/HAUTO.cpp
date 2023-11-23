#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int Caculate(string bieuThuc)
{
    stack<int> operandStack;

    istringstream iss(bieuThuc);
    string token;

    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            operandStack.push(stoi(token));
        }
        else
        {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            if (token == "+")
            {
                operandStack.push(operand1 + operand2);
            }
            else if (token == "-")
            {
                operandStack.push(operand1 - operand2);
            }
            else if (token == "*")
            {
                operandStack.push(operand1 * operand2);
            }
        }
    }

    return operandStack.top();
}

int main()
{
    string bieuThuc;
    getline(cin, bieuThuc);

    int ketQua = Caculate(bieuThuc);

    cout << ketQua << endl;

    return 0;
}
