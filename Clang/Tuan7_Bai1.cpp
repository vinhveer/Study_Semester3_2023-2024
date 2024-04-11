#include <stdio.h>
#include <string.h>

void Input(char* a)
{
    do
    {
        printf("Nhập chuỗi ký tự: ");
        fgets(a, 30, stdin);
        a[strcspn(a, "\n")] = '\0';
    } while (strlen(a) < 1 || strlen(a) > 30);
}

void Output(char* a)
{
    printf("Chuỗi ký tự hiện tại là: %s \n", a);
}

int PosDoubleSpace(char* a)
{
    for (int i = 0; i < strlen(a); i++)
        if (a[i] == ' ' && a[i+1] == ' ')
            return i+1;
    return -1;
}

void RemoveChar(char *a)
{
    int pos;
    do
    {
        printf("Nhập vị trí ký tự cần xoá: ");
        scanf("%d", &pos);
    } while (pos < 1 || pos > strlen(a));
    
    for (int i = pos; i < strlen(a);i++)
        a[i] = a[i+1];
}

void StringNormalization(char* a)
{
    int i = 0;
    int j = 0;
    while (a[i] != '\0')
    {
        // Skip leading spaces
        while (a[i] == ' ')
            i++;
        
        // Copy non-space characters to the beginning of the string
        while (a[i] != ' ' && a[i] != '\0')
        {
            a[j] = a[i];
            i++;
            j++;
        }
        
        // Add a single space after each word
        if (a[i] == ' ')
        {
            a[j] = ' ';
            j++;
        }
    }
    
    // Terminate the normalized string with a null character
    a[j] = '\0';
}

int main()
{
    char a[30];
    Input(a);
    Output(a);
    printf("Vị trí đầu tiên có hai dấu cách là: %d\n", PosDoubleSpace(a));
    RemoveChar(a);
    Output(a);
    StringNormalization(a);
    Output(a);
}