#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node *next;
};

Node *head = nullptr;

Node *CreateNode(int value)
{
    Node *node = new Node;
    node->info = value;
    node->next = NULL;
    return node;
}

void InsertAbove(int value)
{
    Node *node = CreateNode(value);
    node -> next = head;
    head = node;
}

void InsertBelow(int value)
{
    Node *node = CreateNode(value);
    if (head == nullptr)
        head = node;
    else
    {
        Node *temp = head;
        while (temp -> next != NULL)
            temp = temp -> next;
        temp -> next = node;
    }
}

void Traverse(Node *head)
{
    Node *node = head;
    while (node -> next != NULL)
    {
        cout << node -> info << " ";
        node = node -> next;
    }
        
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        InsertBelow(temp);
    }
    Traverse(head);
    return 0;
}