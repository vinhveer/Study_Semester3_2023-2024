#include <stdio.h>
#include <string.h>

void Input(char str[])
{
    int count = 0;
    do
    {
        printf("Hay nhap chuoi ky tu: ");
        gets(str);
        count = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == ' ')
            {
                count += 1;
            }
        }
    } while (count < 1 || strlen(str) > 100);
}

int CountAlphabet(char str[])
{
    int count = 0;
    for (int i = 0; i < strlen(str); i++)
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            count += 1;
    return count;
}

int Compare(char str[])
{
    int lenfirststr = 0;
    int lenlaststr = 0;
    int count = 0;
    int i = 0;
    while (str[i] != ' ')
    {
        lenfirststr += 1;
        i += 1;
    }
    i = strlen(str) - 1;
    while (str[i] != ' ')
    {
        lenlaststr += 1;
        i -= 1;
    }
    if (lenfirststr > lenlaststr)
        return 1;
    else if (lenfirststr < lenlaststr)
        return -1;
    else
        return 0;
}

void RemoveEnd(char str[])
{
    int i = strlen(str) - 1;
    while (str[i] != ' ')
    {
        str[i] = '\0';
        i -= 1;
    }
}

void InsertChar(char str[])
{
    int n;
    printf("Nhap so luong ky tu can them vao: ");
    scanf("%d", &n);
    int i = strlen(str);
    while (n != 0)
    {
        str[i] = '?';
        str[i+1] = '\0';
        i += 1;
        n -= 1;
    }
}

int main()
{
    char str[100];
    Input(str);
    printf("So luong ky tu chu cai la: %d\n", CountAlphabet(str));
    printf("Ket qua so sanh ky tu: %d\n", Compare(str));
    RemoveEnd(str);
    printf("%s\n", str);
    InsertChar(str);
    printf("%s\n", str);
}