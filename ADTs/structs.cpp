#include <iostream>
#include <string>
using namespace std;
/*
    This one is quite easy, its just structs, make sure to use dot notation (e.g. s.name) when calling a struct
    know that a struct is public by default BUT can have methods and private members (although rarely used)
    know how to deal with data in a struct shown in functions below
 */

// struct declaration and defintion
struct student
{
    string name;
    int id;
    double grade;
};

// inputs struct members
void inputStudent(student &s)
{
    cout << "Enter name: ";
    cin >> s.name;

    cout << "Enter ID: ";
    cin >> s.id;

    cout << "Enter grade: ";
    cin >> s.grade;
}

// prints struct members
void printStudent(const student &s)
{
    cout << s.name << " " << s.id << " " << s.grade << endl;
}

int main()
{
    const int SIZE = 3;
    student students[SIZE];

    cout << "=== Input Students ===" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "\nStudent " << i + 1 << ":\n";
        inputStudent(students[i]);
    }

    cout << "\n=== Stored Student Records ===\n";
    for (int i = 0; i < SIZE; i++)
    {
        printStudent(students[i]);
    }

    return 0;
}