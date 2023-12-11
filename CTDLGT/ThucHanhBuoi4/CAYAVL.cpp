#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

int isBalanced(struct Node *node)
{
    if (node == NULL)
        return 1;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

struct Node *createNode(int x)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *insertNode(struct Node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);

    return node;
}

int main()
{
    struct Node *root = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }

    if (isBalanced(root))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
