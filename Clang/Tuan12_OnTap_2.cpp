#include <stdio.h>
#include <string.h>

void Input(char str[])
{
    printf("Nhap chuoi: ");
    gets(str);
}

int CountWord(char str[])
{
    int count = 1;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == ' ')
            count += 1;
    return count;
}

void RemoveChar(char str[])
{
    char c;
    int i = 0;
    printf("Nhap ky tu can xoa: ");
    scanf("%c", &c);
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            for (int j = i; j < strlen(str); j++)
                str[j] = str[j+1];
            str[strlen(str)] = '\0';
        }
        else
            i++;
    }
}

void ConvertWord(char str[]) {
    int i = 0, j = 0, pos = 0;
    char firstword[100] = "";
    char betweenstr[100] = "";
    char lastword[100] = "";

    while (str[i] != ' ' && str[i] != '\0') {
        firstword[i] = str[i];
        i++;
    }
    firstword[i] = '\0';

    i = strlen(str) - 1;
    while (str[i] != ' ' && i >= 0) {
        lastword[j] = str[i];
        i--;
        j++;
    }
    lastword[j] = '\0';

    i = strlen(firstword);
    pos = 0;
    j = strlen(str) - strlen(lastword) - 1;
    while (i < j) {
        betweenstr[pos] = str[i];
        i++;
        pos++;
    }
    betweenstr[pos] = '\0';

    printf("FirstWord: %s, LastWord: %s, BetweenWord: %s\n", firstword, lastword, betweenstr);
}

int main()
{
    char str[100];
    Input(str);
    printf("So tu co trong chuoi: %d\n", CountWord(str));
    RemoveChar(str);
    printf("%s", str);
    ConvertWord(str);
}