#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây AVL
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

// Hàm để tạo một nút mới với giá trị key cụ thể
Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // Mỗi nút mới sẽ có chiều cao là 1
    return node;
}

// Hàm để tính chiều cao của một nút
int height(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

// Hàm để cập nhật chiều cao của một nút dựa trên chiều cao của con trái và con phải
void updateHeight(Node *node)
{
    node->height = 1 + max(height(node->left), height(node->right));
}

// Hàm để lấy hiệu số cân bằng của một nút
int balanceFactor(Node *node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Hàm để xoay cây sang phải khi cân bằng bị đảo ngược (Left-Left)
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Hàm để xoay cây sang trái khi cân bằng bị đảo ngược (Right-Right)
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Hàm để chèn một key vào cây AVL
Node *insert(Node *root, int key)
{
    // Bước 1: Thực hiện chèn giống như cây BST thông thường
    if (root == nullptr)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else // Trường hợp key đã tồn tại
        return root;

    // Bước 2: Cập nhật chiều cao của nút hiện tại
    updateHeight(root);

    // Bước 3: Lấy hiệu số cân bằng để kiểm tra xem cây có còn cân bằng không
    int balance = balanceFactor(root);

    // Bước 4: Cân bằng lại cây nếu cần
    // 4.1: Left Left Case
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);

    // 4.2: Right Right Case
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);

    // 4.3: Left Right Case
    if (balance > 1 && key > root->left->key)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // 4.4: Right Left Case
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Hàm để duyệt cây theo thứ tự trung tâm (inorder)
void inorderTraversal(Node *root)
{
    if (root != nullptr)
    {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// Hàm chính
int main()
{
    Node *root = nullptr;

    // Chèn các phần tử vào cây
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // In ra cây AVL đã tạo
    cout << "Inorder Traversal of AVL tree: ";
    inorderTraversal(root);

    return 0;
}
