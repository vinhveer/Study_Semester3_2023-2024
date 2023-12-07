#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

struct Node
{
    int pos;
    int info;
    Node *next;
};

Node *head = nullptr;
int pos = 0;

// Tạo nút
Node *CreateNode(int value, int pos_value)
{
    Node *node = new Node;
    node->pos = pos_value;
    node->info = value;
    node->next = nullptr;
    return node;
}

// Chèn cuối
void InsertAtEnd(int value, int pos_value)
{
    Node *newNode = CreateNode(value, pos_value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Sắp xếp danh sách liên kết
void SortLinkedList()
{
    if (head == nullptr || head->next == nullptr)
        return;

    for (Node *i = head; i != nullptr; i = i->next)
    {
        for (Node *j = i->next; j != nullptr; j = j->next)
        {
            if (i->pos > j->pos)
            {
                int tempPos = i->pos;
                i->pos = j->pos;
                j->pos = tempPos;

                int tempInfo = i->info;
                i->info = j->info;
                j->info = tempInfo;
            }
        }
    }
}

// Kiểm tra có phải là số hay không?
void IsNumber(char text)
{
    if (isdigit(text))
    {
        int num = atoi(&text);
        InsertAtEnd(num, pos);
        pos++;
    }
}

// Kiểm tra có phải là chuỗi đối xứng không
bool IsPalindrome()
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *prev = nullptr;
    Node *curr = slow;
    Node *nextNode;

    while (curr != nullptr)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    Node *firstHalf = head;
    while (prev != nullptr)
    {
        if (firstHalf->info != prev->info)
            return false;

        firstHalf = firstHalf->next;
        prev = prev->next;
    }

    return true;
}

// Xoá nút
void DeleteNode(Node *toDelete)
{
    if (toDelete == nullptr)
        return;

    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr && temp != toDelete)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
        return;

    if (prev == nullptr)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
}

void SelectAndSortTopK(int k)
{
    Node *temp = head;
    Node *prev = nullptr;

    for (int i = 0; i < k && temp != nullptr; ++i)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev != nullptr)
    {
        prev->next = nullptr;
    }

    Node *deleteTemp = temp;
    while (temp != nullptr)
    {
        cout << "(" << temp->info << "," << temp->pos << ") ";
        Node *nextNode = temp->next;
        delete deleteTemp;
        temp = nextNode;
        deleteTemp = nextNode;
    }
    cout << endl;
}



int main()
{
    string input;
    cout << "Enter a string of characters with interleaved digits: ";
    getline(cin, input);

    pos = 0;
    for (char c : input)
    {
        IsNumber(c);
    }

    SortLinkedList();

    Node *temp = head;
    cout << "Sorted Linked List: ";
    while (temp != nullptr)
    {
        cout << "(" << temp->info << "," << temp->pos << ") ";
        temp = temp->next;
    }
    cout << endl;

    if (IsPalindrome())
    {
        cout << "The sequence is a palindrome." << endl;
    }
    else
    {
        cout << "The sequence is not a palindrome." << endl;
    }

    int k = 5;
    SelectAndSortTopK(k);

    temp = head;
    while (temp != nullptr)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
