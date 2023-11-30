#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node
{
    int data;
    node *left;
    node *right;
};

node *TaoNut(int x)
{
    node *newNode = new node;
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Chen(node *&root, int x, int y)
{
    if (x > y)
        return;
    int m = (x + y) / 2;
    root = TaoNut(m);
    Chen(root->left, x, m - 1);
    Chen(root->right, m + 1, y);
}

void Duyet(node *root)
{
    if (root == NULL)
        return;
    Duyet(root->left);
    Duyet(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    int h;
    cin >> h;
    int n = pow(2, h) - 1;
    Chen(root, 1, n);
    Duyet(root);
}