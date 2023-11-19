#include <iostream>
using namespace std;

struct Node
{
    int const_value;
    int pow;
    Node *next;
};
Node *head = NULL;

Node *CreateNode(int const_value, int pow)
{
    Node *n = new Node;
    n->const_value = const_value;
    n->pow = pow;
    n->next = NULL;
    return n;
}

void ChenCuoi(Node *&head, int const_value, int pow)
{
    Node *n = CreateNode(const_value, pow);
    if (head == NULL)
        head = n;
    else
    {
        Node *p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = n;
    }
}

void Browse(Node *head)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->const_value > 1)
        {
            if (p != head)
                cout << "+";
            cout << p->const_value;
        }
        else if (p->const_value != 1)
            cout << p->const_value;

        if (p->pow != 0)
        {
            cout << "x";
            if (p->pow != 1)
                cout << "^" << p->pow;
        }

        p = p->next;
    }
}

int main()
{
    int const_value;
    int pow;
    cin >> const_value >> pow;
    while (const_value != 0 || pow != 0)
    {
        ChenCuoi(head, const_value, pow);
        cin >> const_value >> pow;
    }
    Browse(head);
    return 0;
}