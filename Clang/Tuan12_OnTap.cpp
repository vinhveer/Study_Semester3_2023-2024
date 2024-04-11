#include <stdio.h>
#include <string.h>

void Input(char s[])
{
    printf("Nhap chuoi ky tu: ");
    gets(s);
}

void StringNormailization(char s[])
{
    char sd[201];
    while (s[0] == ' ')
        strcpy(s, &s[1]);
    while (s[strlen(s) - 1] == ' ')
        s[strlen(s) - 1] = NULL;
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            strcpy(sd, s);
            s[i] = NULL;
            strcat(s, &sd[i + 1]);
            i--;
        }
}

int IsPalindrome(char s[])
{
    int i = 0;
    int j = strlen(s) - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }

    return 1;
}

int CountCharacter(char s[])
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
        if (s[i] = 'k')
            count += 1;
    return count;
}

void SortAlphabet(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            for (int j = 0; j < strlen(s); j++)
                if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z'))
                    if (s[i] < s[j])
                    {
                        char temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
}

void SortNumber(char s[])
{
    for (int i = 0; i < strlen(s); i++)
        if (s[i] >= '0' && s[i] <= '9')
            for (int j = 0; j < strlen(s); j++)
                if (s[j] >= '0' && s[j] <= '9')
                    if (s[i] < s[j])
                    {
                        char temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
}

int main()
{
    char s[200];
    Input(s);
    StringNormailization(s);
    printf("%s\n", s);
    printf("Ket qua xau doi xung: %d\n", IsPalindrome(s));
    SortAlphabet(s);
    printf("%s\n", s);
    SortNumber(s);
    printf("%s\n", s);
}