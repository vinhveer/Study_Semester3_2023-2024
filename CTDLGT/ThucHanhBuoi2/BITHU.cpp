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
    Node(char val) : data(val), left(nullptr), right(nullptr) {} // Hàm tạo Node
};

// Kiem tra xem co phai la toan tu khong
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Tinh chieu cao
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
    // Nhap bieu thuc
    string expression;
    getline(cin, expression);

    stack<Node *> s;

    // Duyet tung ki tu
    for (char c : expression)
    {
        if (isalpha(c)) // Neu la so hang, tao nut moi va dua vao stack
        {
            s.push(new Node(c));
        }
        else if (isOperator(c)) // Neu la toan tu, gan nut
        {
            Node *newNode = new Node(c);
            newNode->right = s.top();
            s.pop();
            newNode->left = s.top();
            s.pop();
            s.push(newNode);
        }
    }

    Node *root = s.top(); // nut goc

    int height = getHeight(root);

    cout << height << endl;

    return 0;
}
