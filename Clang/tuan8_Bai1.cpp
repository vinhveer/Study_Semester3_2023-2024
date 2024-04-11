#include <stdio.h>
#include <string.h>

void Input(char str[])
{
    do
    {
        printf("Nhap chuoi ky tu: ");
        gets(str);
        if (str == "" || strlen(str) > 30)
            printf("Vui long nhap lai!\n");
    } while (str == "" || strlen(str) > 30);
}

int PositionSpace(char str[])
{
    for (int i = 0; i < (strlen(str) - 1); i++)
    {
        if (str[i] == " " && str[i + 1] == " ")
        {
            return i;
            break;
        }
    }
}