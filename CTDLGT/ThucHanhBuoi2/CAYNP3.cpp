#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *Chen(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = Chen(root->left, value);
    }
    else
    {
        root->right = Chen(root->right, value);
    }

    return root;
}

void Duyet(Node *root)
{
    if (root != nullptr)
    {
        Duyet(root->left);
        Duyet(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    int n;
    cin >> n;

    Node *root = nullptr;

    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        root = Chen(root, value);
    }

    Duyet(root);

    return 0;
}
