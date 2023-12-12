#include <iostream>

using namespace std;

// Định nghĩa một nút trong danh sách liên kết
struct Node
{
    int data;
    Node *next;
};

// Hàm thêm một phần tử vào cuối danh sách liên kết
Node *append(Node *head, int value)
{
    Node *newNode = new Node{value, nullptr};
    if (head == nullptr)
    {
        return newNode;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
}

// Hàm xoá một phần tử khỏi danh sách liên kết
Node *remove(Node *head, int value)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    // Xử lý trường hợp phần tử cần xoá là phần tử đầu tiên
    if (head->data == value)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    // Duyệt danh sách để tìm phần tử cần xoá
    Node *current = head;
    while (current->next != nullptr && current->next->data != value)
    {
        current = current->next;
    }

    // Xoá phần tử nếu tìm thấy
    if (current->next != nullptr)
    {
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    return head;
}

// Hàm duyệt và in các phần tử trong danh sách liên kết
void traverseAndPrint(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Hàm xoá toàn bộ danh sách liên kết
void clear(Node *&head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *myList = nullptr;

    // Thêm các phần tử vào danh sách liên kết
    myList = append(myList, 1);
    myList = append(myList, 2);
    myList = append(myList, 3);

    // In danh sách liên kết
    cout << "Danh sach lien ket ban dau: ";
    traverseAndPrint(myList);

    // Xoá phần tử có giá trị là 2
    myList = remove(myList, 2);
    cout << "Danh sach lien ket sau khi xoa phan tu co gia tri 2: ";
    traverseAndPrint(myList);

    // Thêm phần tử mới
    myList = append(myList, 4);
    cout << "Danh sach lien ket sau khi them phan tu moi: ";
    traverseAndPrint(myList);

    // Xóa toàn bộ danh sách liên kết
    clear(myList);

    return 0;
}
