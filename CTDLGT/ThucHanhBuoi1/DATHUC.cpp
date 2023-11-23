#include <iostream>
#include <cmath>

using namespace std;

struct Node
{
    int hs; // coefficient
    int mu; // power
    Node *next;
};

// Hàm thêm một node vào cuối danh sách
void ThemNode(Node *&head, int hs, int mu)
{
    Node *temp = new Node{hs, mu, nullptr};
    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        Node *p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

// Hàm in đa thức
void InDaThuc(Node *head)
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->hs > 0 && p != head)
            cout << "+";
        if (p->hs < 0)
            cout << "-";

        int hs = abs(p->hs);
        if (hs != 1 || p->mu == 0)
            cout << hs;

        if (p->mu > 0)
            cout << "x";
        if (p->mu > 1)
            cout << "^" << p->mu;

        p = p->next;
    }
}

// Hàm giải phóng bộ nhớ của danh sách
void GiaiPhongBoNho(Node *head)
{
    Node *p = head;
    while (p != nullptr)
    {
        Node *temp = p;
        p = p->next;
        delete temp;
    }
}

int main()
{
    Node *head = nullptr;
    int a, b;

    do
    {
        cin >> a >> b;
        if (a != 0)
            ThemNode(head, a, b);
    } while (a != 0);

    InDaThuc(head);

    // Giải phóng bộ nhớ
    GiaiPhongBoNho(head);

    return 0;
}
