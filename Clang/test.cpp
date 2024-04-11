#include <stdio.h>
#include <string.h>

int main()
{
    char value[100];
    gets(value);
    printf("%d", strlen(value));
}