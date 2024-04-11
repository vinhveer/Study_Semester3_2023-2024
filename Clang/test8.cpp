#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string first_name;
    string last_name;
    int student_code;
    string class_name;
    string date_of_birth;
    double medium_score;
};

// Function to input student information
void input_student_information(Student &student)
{
    cout << "Enter student's first name: ";
    cin >> student.first_name;
    cout << "Enter student's last name: ";
    cin >> student.last_name;
    cout << "Enter student's student code: ";
    cin >> student.student_code;
    cout << "Enter student's class name: ";
    cin >> student.class_name;
    cout << "Enter student's date of birth: ";
    cin >> student.date_of_birth;
    cout << "Enter student's medium score: ";
    cin >> student.medium_score;
}

// Function to print student information
void print_student_information(const Student &student)
{
    cout << "Student's first name: " << student.first_name << endl;
    cout << "Student's last name: " << student.last_name << endl;
    cout << "Student's student code: " << student.student_code << endl;
    cout << "Student's class name: " << student.class_name << endl;
    cout << "Student's date of birth: " << student.date_of_birth << endl;
    cout << "Student's medium score: " << student.medium_score << endl;
}

// Function to input the list of students
void input_list_of_students(vector<Student> &students)
{
    int number_of_students;
    cout << "Enter the number of students: ";
    cin >> number_of_students;
    for (int i = 0; i < number_of_students; i++)
    {
        Student student;
        input_student_information(student);
        students.push_back(student);
    }
}

// Function to print list of students
void print_list_of_students(const vector<Student> &students)
{
    for (int i = 0; i < students.size(); i++)
    {
        print_student_information(students[i]);
    }
}

// Function to find and return student information by code
Student find_student_by_code(const vector<Student> &students, int student_code)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].student_code == student_code)
        {
            return students[i];
        }
    }
    return Student(); // Return an empty student object if no student is found.
}

// Function to find and return student information by name
Student find_student_by_name(const vector<Student> &students, string first_name, string last_name)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].first_name == first_name && students[i].last_name == last_name)
        {
            return students[i];
        }
    }
    return Student(); // Return an empty student object if no student is found.
}

// Function to sort the list of students in ascending order by class, descending by process score
void sort_list_of_students(vector<Student> &students)
{
    sort(students.begin(), students.end(), [](const Student &a, const Student &b)
         { return a.class_name < b.class_name || (a.class_name == b.class_name && a.medium_score > b.medium_score); });
}

// Function to filter and return a list of students by class
vector<Student> filter_list_of_students_by_class(const vector<Student> &students, string class_name)
{
    vector<Student> filtered_students;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].class_name == class_name)
        {
            filtered_students.push_back(students[i]);
        }
    }
    return filtered_students;
}

int main()
{
    vector<Student> students;
    input_list_of_students(students);
    // Print the list of students.
    print_list_of_students(students);
    // Find and print the student information by code.
    int student_code;
    cout << "Enter the student code: ";
    cin >> student_code;
    Student student = find_student_by_code(students, student_code);
    if (student.student_code != 0)
    {
        print_student_information(student);
    }
    else
    {
        cout << "No student found with the given code." << endl;
    }
    // Find and print the student information by name.
    string first_name, last_name;
    cout << "Enter the student's first name: ";
    cin >> first_name;
    cout << "Enter the student's last name: ";
    cin >> last_name;
    student = find_student_by_name(students, first_name, last_name);
    if (student.student_code != 0)
    {
        print_student_information(student);
    }
    else
    {
        cout << "No student found with the given name." << endl;
    }
    // Sort the list of students in ascending order by class, descending by process score.
    sort_list_of_students(students);
    // Print the sorted list of students.
    print_list_of_students(students);
    // Filter and print a list of students by class.
    string class_name;
    cout << "Enter the class name: ";
    cin >> class_name;
    vector<Student> filtered_students = filter_list_of_students_by_class(students, class_name);
    if (filtered_students.size() > 0)
    {
        print_list_of_students(filtered_students);
    }
    else
    {
        cout << "No students found in the given class." << endl;
    }
    return 0;
}
