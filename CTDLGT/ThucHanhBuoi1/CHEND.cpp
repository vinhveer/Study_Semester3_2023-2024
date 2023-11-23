#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};
Node *head;

Node *TaoNut(int x)
{
    Node *n = new Node;
    n->info = x;
    n->next = NULL;
    return n;
}

void ChenDau(Node *&head, int x)
{
    Node *p = TaoNut(x);
    p->next = head;
    head = p;
}

void Duyet(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

int main()
{
    int n;
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ChenDau(head, temp);
    }
    Duyet(head);
}
