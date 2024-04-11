#include <stdio.h>
#include <string.h>

void left(char src[], int n)
{
    char dest[];
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

void mid(char s[], int n, int m) {
    char st[];
    for(int i=n;i<n+m;i++) {
        st[i]=s[i];
    }
    st[i]='\0';
    return st;
}

int main()
{
    
}
