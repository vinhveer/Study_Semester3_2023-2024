#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

Node *head = nullptr;

Node *TaoNut(int value)
{
    Node *n = new Node;
    n -> info = value;
    n -> next = NULL;
    return n;
}

void InsertAbove(Node *head, int value)
{
    Node *p = TaoNut(value);
    p -> next = head;
    head = p;
}

void Duyet(Node *node)
{
    while (node -> next != NULL)
        cout << node -> info;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        InsertAbove(head, temp);
    }

    Duyet(head);
}