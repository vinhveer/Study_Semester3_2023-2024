#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    // a la don vi
    int a = n % 10;
    // b la chuc
    int b = (n / 10) % 10;
    // c la hang tram
    int c = (n / 100) % 10;
    // d la hang nghin
    int d = (n / 1000) % 10;
    // e la hang chuc nghin
    int e = (n / 10000) % 10;
    // f la hang tram nghin
    int f = (n / 100000) % 10;
    switch (f)
    {
    case 1:
        printf("mot tram ");
        break;
    case 2:
        printf("hai tram ");
        break;
    case 3:
        printf("ba tram ");
        break;
    case 4:
        printf("bon tram ");
        break;
    case 5:
        printf("nam tram ");
        break;
    case 6:
        printf("sau tram ");
        break;
    case 7:
        printf("bay tram ");
        break;
    case 8:
        printf("tam tram ");
        break;
    case 9:
        printf("chin tram ");
        break;
    }
    if (e % 10000 == 0 && d != 0 && n > 100000)
    {
        printf("le ");
    }
    switch (e)
    {
    case 1:
        printf("muoi ");
        break;
    case 2:
        printf("hai muoi ");
        break;
    case 3:
        printf("ba muoi ");
        break;
    case 4:
        printf("bon muoi ");
        break;
    case 5:
        printf("nam muoi ");
        break;
    case 6:
        printf("sau muoi ");
        break;
    case 7:
        printf("bay muoi ");
        break;
    case 8:
        printf("tam muoi ");
        break;
    case 9:
        printf("chin muoi ");
        break;
    }
    switch (d)
    {
    case 0:
        if (n > 1000)
            printf("nghin ");
        break;
    case 1:
        printf("mot nghin ");
        break;
    case 2:
        printf("hai nghin ");
        break;
    case 3:
        printf("ba nghin ");
        break;
    case 4:
        printf("bon nghin ");
        break;
    case 5:
        if (n < 10000 || e == 0)
        {
            printf("nam nghin ");
            break;
        }
        else
        {
            printf("lam nghin ");
            break;
        }
    case 6:
        printf("sau nghin ");
        break;
    case 7:
        printf("bay nghin ");
        break;
    case 8:
        printf("tam nghin ");
        break;
    case 9:
        printf("chin nghin ");
        break;
    }
    switch (c)
    {
    case 0:
        if ((a != 0 && b == 0 || a == 0 && b != 0 || (a != 0 && b != 0 && n > 1000)) && n > 100)
            printf("khong tram ");
        break;
    case 1:
        printf("mot tram ");
        break;
    case 2:
        printf("hai tram ");
        break;
    case 3:
        printf("ba tram ");
        break;
    case 4:
        printf("bon tram ");
        break;
    case 5:
        printf("nam tram ");
        break;
    case 6:
        printf("sau tram ");
        break;
    case 7:
        printf("bay tram ");
        break;
    case 8:
        printf("tam tram ");
        break;
    case 9:
        printf("chin tram ");
        break;
    }
    if (b % 10 == 0 && a != 0 && n > 100)
    {
        printf("le ");
    }
    switch (b)
    {
    case 1:
        printf("muoi ");
        break;
    case 2:
        printf("hai muoi ");
        break;
    case 3:
        printf("ba muoi ");
        break;
    case 4:
        printf("bon muoi ");
        break;
    case 5:
        printf("nam muoi ");
        break;
    case 6:
        printf("sau muoi ");
        break;
    case 7:
        printf("bay muoi ");
        break;
    case 8:
        printf("tam muoi ");
        break;
    case 9:
        printf("chin muoi ");
        break;
    }
    switch (a)
    {
    case 0:
        if (n < 1)
            printf("khong");
        break;
    case 1:
        printf("mot ");
        break;
    case 2:
        printf("hai ");
        break;
    case 3:
        printf("ba ");
        break;
    case 4:
        printf("bon ");
        break;
    case 5:
        if (n < 10 || b == 0)
        {
            printf("nam ");
            break;
        }
        else
        {
            printf("lam ");
            break;
        }
    case 6:
        printf("sau ");
        break;
    case 7:
        printf("bay ");
        break;
    case 8:
        printf("tam ");
        break;
    case 9:
        printf("chin ");
        break;
    }
}
