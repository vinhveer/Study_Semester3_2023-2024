#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->val = value;
    newNode->next = nullptr;
    return newNode;
}

Node *moveHeadToTail(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *newHead = head->next;
    Node *current = newHead;

    while (current->next)
    {
        current = current->next;
    }

    current->next = head;
    head->next = nullptr;

    return newHead;
}

void printList(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteList(Node *head)
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    int n;
    cin >> n;

    Node *head = nullptr;

    if (n > 0)
    {
        int value;
        cin >> value;
        head = createNode(value);

        Node *current = head;

        for (int i = 1; i < n; ++i)
        {
            cin >> value;
            current->next = createNode(value);
            current = current->next;
        }
    }

    Node *newHead = moveHeadToTail(head);

    printList(newHead);

    deleteList(newHead);

    return 0;
}
