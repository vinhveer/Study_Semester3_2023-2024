#include <stdio.h>
#define PATH "file.txt"

void WriteFile()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    FILE *fp = fopen(PATH, "w+");
    if (fp == NULL)
    {
        printf("File does not exist. Please try with a different path!\n");
        return;
    }

    fprintf(fp, "%d", number);
    fclose(fp);
}

void ReadFile()
{
    int number;
    FILE *fp = fopen(PATH, "r+");
    if (fp == NULL)
    {
        printf("File does not exist. Please try with a different path!\n");
        return;
    }

    fscanf(fp, "%d", &number);
    fclose(fp);

    printf("The number just read is: %d", number);
}

int main()
{
    WriteFile();
    ReadFile();
    return 0;
}
