#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void Duyet(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        Duyet(root->left);
        Duyet(root->right);
    }
}

Node *TaoCay(int arr[], int n, int i)
{
    if (i < n)
    {
        Node *temp = new Node(arr[i]);
        temp->left = TaoCay(arr, n, 2 * i + 1);
        temp->right = TaoCay(arr, n, 2 * i + 2);
        return temp;
    }
    return nullptr;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Node *root = TaoCay(arr, n, 0);

    Duyet(root);

    return 0;
}
