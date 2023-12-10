#include <iostream>
using namespace std;

#define PATH "file_float.txt"
#define MAX 50

void WriteFile()
{
    int count;
    printf("Enter a count value: ");
    scanf("%d", &count);

    FILE *fp = fopen(PATH, "w+");
    if (fp == NULL)
    {
        printf("File does not exist. Please try with a different path!\n");
        return;
    }

    float temp;
    fprintf(fp, "%d ", count);
    for (int i = 0; i < count; i++)
    {
        scanf("%f", &temp);
        fprintf(fp, "%0.2f ", temp);
    }

    fclose(fp);
}

void ReadFile(float array[])
{
    FILE *fp = fopen(PATH, "r");
    if (fp == NULL)
    {
        printf("File does not exist or cannot be opened. Please try with a different path!\n");
        return;
    }

    int count = 0;
    float number;
    printf("Numbers read from the file:\n");

    while (fscanf(fp, "%f", &number) != EOF)
    {
        printf("%0.2f ", number);
        array[count] = number;
        count++;
    }

    printf("\nNumbers in the array:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%0.2f ", array[i]);
    }

    fclose(fp);
}

int main()
{
    WriteFile();
    float array[MAX];
    ReadFile(array);
    return 0;
}