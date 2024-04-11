#include <stdio.h>
#include <string.h>

void Input(char str[])
{
    printf("Nhap chuoi: ");
    gets(str);
}

void MaxWord(char str[])
{
    int len = 0;
    int maxlen = 0;
    int pos = 0;
    int maxpos = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ' ')
        {
            if (maxlen < len)
            {
                maxlen = len;
                maxpos = pos;
            }
            pos = i + 1;
        }
        else
        {
            len += 1;
        }

    printf("Tai vi tri: %d\n", maxpos);
}

int main()
{
    char str[100];
    Input(str);
    printf("%s\n", str);
    MaxWord(str);
}