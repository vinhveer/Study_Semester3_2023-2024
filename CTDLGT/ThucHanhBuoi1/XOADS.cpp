#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *TaoNut(int x)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = x;
    node->next = NULL;
    return node;
}

void ChenCuoi(struct Node **head, int x)
{
    struct Node *newNode = TaoNut(x);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void XoaPhanTu(struct Node **head, int x)
{
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == x)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != x)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return;
    }

    prev->next = temp->next;

    free(temp);
}

void HienThi(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    int n, x;
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        ChenCuoi(&head, data);
    }

    XoaPhanTu(&head, x);

    HienThi(head);

    return 0;
}
