#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DateID
{
    int dd, mm, yyyy;
};

struct StudentInfo
{
    char StudentName[51];
    char StudentID[9];
    char Class[12];
    Date DateOfBirth;
    float AvgGrade;
}

void
InputStudentInfo(StudentInfo &student)
{
    do
    {
        printf("Enter Student Full-name: ");
        getchar(student.StudentName);
    } while (strlen(student.StudentName) < 1 || strlen(student.StudentName) > 50);
    do
    {
        printf("Enter StudentID: ");
        getchar(student.StudentID);
    } while (strlen(student.StudentID) < 1 || strlen(student.StudentID) > 9);
    do
    {
        printf("Enter Class: ");
        getchar(student.Class);
    } while (strlen(student.StudentClass) < 1 || strlen(student.StudentClass) > 12);
    printf("Enter Student Date of Birth: ");
    InputDay(student.DateOfBirth);
    do
    {
        printf("Enter Student Average Grade: ")
            scanf("%f", &student.AvgGrade);
    } while ((student.AvgGrade) < 0 || strlen(student.AvgGrade) > 10);
}
void OutputStudentInfo(StudentInfo student)
{
    printf("%s \t %s \t %s \t %d/%d/%d \t %0.2f",
            student.StudentName,
            student.StudentID,
            student.Class,
            student.DateOfBirth.dd,student.DateOfBirth.mm,student.DateOfBirth.yyyy,
            student.AvgGrade);
}
void InputDay(DateID &dateinfo)
{
    do
    {
        printf("Enter Date (dd): ");
        scanf("%d", &dateinfo.dd);
    } while (dateinfo.dd < 1 || dateinfo.dd >= 31);
    switch (dateinfo.dd)
    {
    case 29:
    {
        do
        {
            printf("Enter Month (mm) :");
            scanf("%d", &dateinfo.mm);
        } while (!(1 <= dateinfo.mm && dateinfo.mm <= 12));
        if (dateinfo.mm == 2)
            do
            {
                printf("Enter Year (yyyy): ");
                scanf("%d", &dateinfo.yyyy);
            } while (!((dateinfo.yyyy % 100 != 0 && dateinfo.yyyy % 4 == 0) || (dateinfo.yyyy % 100 == 0 && dateinfo.yyyy % 400 == 0)));
        else
            do
            {
                printf("Enter Year (yyyy): ");
                scanf("%d", &dateinfo.yyyy);
            } while (!(dateinfo.yyyy >= 1900));
    }
    break;
    case 30:
    {
        do
        {
            printf("Enter Month (mm): ");
            scanf("%d", &dateinfo.mm);
        } while (!(1 <= dateinfo.mm && dateinfo.mm <= 12 && dateinfo.mm != 2));
        do
        {
            printf("Enter Year (yyyy): ");
            scanf("%d", &dateinfo.yyyy);
        } while (!(dateinfo.yyyy >= 1900));
    }
    break;
    case 31:
    {
        do
        {
            printf("Enter Month (mm): ");
            scanf("%d", &dateinfo.mm);
        } while (!(dateinfo.mm == 1 || dateinfo.mm == 3 || dateinfo.mm == 5 || dateinfo.mm == 7 || dateinfo.mm == 8 || dateinfo.mm == 10 || dateinfo.mm == 12));
        do
        {
            printf("Enter Year (yyyy): ");
            scanf("%d", &dateinfo.yyyy);
        } while (!(dateinfo.yyyy >= 1900));
    }
    break;
    default:
    {
        do
        {
            printf("Enter Month (mm): ");
            scanf("%d", &dateinfo.mm);
        } while (!(1 <= dateinfo.mm && dateinfo.mm <= 12));
        do
        {
            printf("Enter Year (yyyy): ");
            scanf("%d", &dateinfo.yyyy);
        } while (!(dateinfo.yyyy >= 1900));
    }
    }
}