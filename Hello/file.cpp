Node *TaoNut(int x)
{
    Node *n = new Node;
    n->info = x;
    n->left = n->right = NULL;
    return n;
}
void main()
{
    root = TaoNut(3);

    Node *p = TaoNut(6);
    root->left = p;

    p = TaoNut(8);
    root->right = p;

    p = TaoNut(7);
    root->right->right = p;
}