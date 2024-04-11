#include <stdio.h>
#include <string.h>

void Input(char str[]) {
    printf("Nhap chuoi ky tu: ");
    gets(str);
}

void DeleteValue(int pos, char str[]) {
    for (int i = pos; i < strlen(str); i++)
        str[i] = str[i+1];
    str[strlen(str)] = '\0';
}

void StringNormalization(char str[])
{
    int i = 0;
    while (str[i] == ' ')
        DeleteValue(i, str);
    i = strlen(str) - 1;
    while (str[i] == ' ')
    {
        str[i] = '\0';
        i -= 1;
    }
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ' && str[i+1] == ' ')
            DeleteValue(i, str);
        else
            i += 1;
    }
}

int main()
{
    char str[100];
    Input(str);
    StringNormalization(str);
    printf("%s\n", str);
    printf("%d", strlen(str));
}
