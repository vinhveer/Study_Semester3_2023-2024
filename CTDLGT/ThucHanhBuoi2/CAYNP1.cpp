#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

Node *buildBinaryTree(vector<int> &arr, int n, int i)
{
    if (i < n)
    {
        Node *temp = new Node(arr[i]);
        temp->left = buildBinaryTree(arr, n, 2 * i + 1);
        temp->right = buildBinaryTree(arr, n, 2 * i + 2);
        return temp;
    }
    return nullptr;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Tạo cây nhị phân từ mảng
    Node *root = buildBinaryTree(arr, n, 0);

    // Duyệt cây theo thứ tự trước (NLR) và in ra màn hình
    preOrderTraversal(root);

    return 0;
}
