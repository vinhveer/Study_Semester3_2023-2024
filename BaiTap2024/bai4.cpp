#include <iostream>
#include <vector>
using namespace std;

struct Student
{
	string name;
	int age;
	float grade;
};

void CreateNewStudent(vector<Student> &Students)
{
	Student newStudent;
	cout << "Name: "; cin >> newStudent.name;
	cout << "Age: "; cin >> newStudent.age;
	cout << "Grade: "; cin >> newStudent.grade;
	
	Students.push_back(newStudent);	
}

void ListStudent(vector<Student> Students)
{
	for (int i = 0; i < Students.size(); i++)
	{
		cout << "Value - " << i << endl;
		cout << Students[i].name << endl;
		cout << Students[i].age << endl;
		cout << Students[i].grade << endl;
	}
	cout << "-----------------";
}

int main()
{
	vector<Student> Students;
	CreateNewStudent(Students);
	ListStudent(Students);
	return 0;
}
