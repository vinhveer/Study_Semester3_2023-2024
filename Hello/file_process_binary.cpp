#include <stdio.h>
#define PATH "file_binary.bin"

void WriteFile()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    FILE *fp = fopen(PATH, "wb");
    if (fp == NULL)
    {
        printf("Cannot open the file for writing. Please try with a different path!\n");
        return;
    }

    fwrite(&number, sizeof(int), 1, fp);
    fclose(fp);
}

void ReadFile()
{
    int number;
    FILE *fp = fopen(PATH, "rb");
    if (fp == NULL)
    {
        printf("Cannot open the file for reading. Please try with a different path!\n");
        return;
    }

    int result = fread(&number, sizeof(int), 1, fp);
    if (result != 1)
    {
        printf("Error reading from the file.\n");
        fclose(fp);
        return;
    }

    fclose(fp);

    printf("The number just read is: %d\n", number);
}

int main()
{
    WriteFile();
    ReadFile();
    return 0;
}
