#include <iostream>
#include <stack>
#include <cmath>
#include <cctype>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int getHeight(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main()
{
    string expression;
    getline(cin, expression);

    stack<Node *> s;

    for (char c : expression)
    {
        if (isalpha(c))
        {
            s.push(new Node(c));
        }
        else if (isOperator(c))
        {
            Node *newNode = new Node(c);
            newNode->right = s.top();
            s.pop();
            newNode->left = s.top();
            s.pop();
            s.push(newNode);
        }
    }

    Node *root = s.top();

    int height = getHeight(root);

    cout << height << endl;

    return 0;
}
