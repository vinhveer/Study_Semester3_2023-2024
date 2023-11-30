#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void postOrderTraversal(Node *root)
{
    if (root != nullptr)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
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
        root = insert(root, value);
    }

    postOrderTraversal(root);

    return 0;
}
