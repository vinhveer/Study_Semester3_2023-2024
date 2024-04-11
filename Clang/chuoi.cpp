#include <stdio.h>
#include <string.h>

char isPalindrome(char str[])
{
    int i, len;
    len = 0;

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != str[strlen(str) - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char str[100];

    printf("Nh?p chu?i: ");
    gets(str);

    if (isPalindrome(str))
    {
        printf("%s la doi xung\n", str);
    }
    else
    {
        printf("%s khong doi xung\n", str);
    }

    return 0;
}
