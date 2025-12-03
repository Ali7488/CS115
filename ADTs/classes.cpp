#include <iostream>
#include <string>
using namespace std;

/*
    for simplicity sake, i will define the class within the declaration to save time and space, but this document
    covers classes, constructors, private and public access, member functions, and functions using classes

    private variables can only be accessed by the class itself, while public variables and functions can be accessed outside the class

    constructors are special member functions that are called when an object of the class is created
    they are used to initialize the object's member variables

    member functions are functions that are defined within the class and can access the class's private variables

    functions using classes can take class objects as parameters and can access the class's public member functions

    note that if this was done in seperate files, the class declaration would go in a header file (.h) and the member function definitions would go in a source file (.cpp)

    in the source file, the header file would be included at the top using #include "headerfile.h", and the member functions would be defined using the scope resolution operator (::) to specify that they belong to the class

    e.g. void Student::setName(string newName) { name = newName; }
*/

class Student //class declaration
{
private: 
    //private access specifier and private variables 
    string name;
    int id;
    double grade;

public:
    Student() : name(""), id(0), grade(0) { cout << "default constructor called"; } //default constructor

    Student(string newName, int newID, int newGrade) : name(newName), id(newID), grade(newGrade) { cout << "parameterized constructor called"; } //parameterized constructor

    Student(const Student& other) : name(other.name), id(other.id), grade(other.grade) { cout << "copy constructor called"; } //copy constructor

    //setter method functions, used to set private variables to new values 
    void setName(string newName) { name = newName; } 
    void setId(int newID) { id = newID; }   
    void setGrade(double newGrade) { grade = newGrade; }

    //getter method functions, used to get the values of private variables when outside the class
    string getName() const { return name; }
    int getID() const { return id; }
    double getGrade() const { return grade; }

    //member function to display student info
    void print() const
    {
        cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << endl;
    }
};

//non member function that takes a Student object as a parameter
void printHonorStatus(const Student& s){
    if(s.getGrade() >= 90){
        cout << s.getName() << " is an honor student with a grade of " << s.getGrade() << endl;
    }
}

int main()
{
    // Create an array of 3 Students
    Student students[3];

    // Fill them using setters
    students[0].setName("Ali");
    students[0].setId(101);
    students[0].setGrade(88.5);

    students[1].setName("Sara");
    students[1].setId(102);
    students[1].setGrade(94.0);

    students[2].setName("Liam");
    students[2].setId(103);
    students[2].setGrade(72.0);

    // Print all students using the member print() function
    cout << "=== Student Records ===\n";
    for (int i = 0; i < 3; i++)
    {
        students[i].print();
    }

    // Call the external function for honor status
    cout << "\n=== Honor Status ===\n";
    for (int i = 0; i < 3; i++)
    {
        printHonorStatus(students[i]);
    }

    return 0;
}
