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
    n->next = nullptr;
    return n;
}

void ChenCuoi(Node *&head, int x)
{
    Node *p = TaoNut(x);
    if (head == nullptr)
    {
        head = p;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void Duyet(Node *head)
{
    Node *p = head;
    while (p != nullptr)
    {
        cout << p->info << " ";
        p = p->next;
    }
}

int main()
{
    int n;
    cin >> n;

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        ChenCuoi(head, temp);
    }

    Duyet(head);

    return 0;
}
