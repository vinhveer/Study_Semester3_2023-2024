#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    double math_grade;
    double literature_grade;
    double english_grade;
};

int main()
{
    int n = 100;
    Student student[100];
    for (int i = 0; i < n; i++)
    {
        cin >> student[i].name;
        cin >> student[i].math_grade;
        cin >> student[i].literature_grade;
        cin >> student[i].english_grade;

        cout << "Name: " << student[i].name << endl;
        cout << "Math grade: " << student[i].math_grade << endl;
        cout << "Literature grade: " << student[i].literature_grade << endl;
        cout << "English grade: " << student[i].english_grade << endl;
    }
    return 0;
}
