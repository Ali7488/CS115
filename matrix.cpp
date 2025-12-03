#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_ASSIGNMENTS = 10;
/*
This program is testing 2D arrays, these functions all interact with teh 2D array.
note that these arrays are NOT dynamic, thats why we have the constants in the top of the file
remember to always pass the columns when passing an array to a function (see all my arrays passed in functions)
these are quite basic and easy, one last thing to note just incase he asks about it
!IN MEMORY, TO SIMULATE 2D ARRAY AS 1D ARRAY WE USE THE FORMULA [i*MAXCOL*j]
*/

// function does a nested for loop to initialize everything in the 2D array to 0
void initializeGrades(double array[][MAX_ASSIGNMENTS], int studentcount, int assignmentcount)
{
    for (int i = 0; i < studentcount; i++)
    {
        for (int j = 0; j < assignmentcount; j++)
        {
            array[i][j] = 0;
        }
    }
}

// single loop since we know the index of the student, and were just iterating through his assignments
void enterGradeForStudent(double array[][MAX_ASSIGNMENTS], int studentIndex, int assignmentcount)
{
    double grade;
    for (int c = 0; c < assignmentcount; c++)
    {
        cout << "Enter Assignment grade for Student: ";
        cin >> grade;
        array[studentIndex][c] = grade;
    }
}

// nested loop printing each row, where each number has a space between them, and each row has a newline
void printGradeTable(double array[][MAX_ASSIGNMENTS], int studentcount, int assignmentcount)
{
    for (int i = 0; i < studentcount; i++)
    {
        for (int j = 0; j < assignmentcount; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

// one loop, saves everything into sum for that student, calculates average and returns it (this is PER student)
double computeStudentAverage(double array[][MAX_ASSIGNMENTS], int studentIndex, int assignmentcount)
{
    double sum = 0, average = 0;
    for (int c = 0; c < assignmentcount; c++)
    {
        sum += array[studentIndex][c];
    }
    average = sum / assignmentcount;
    return average;
}

// main function to test all previous functions
int main()
{
    double gradeTable[MAX_STUDENTS][MAX_ASSIGNMENTS];

    int studentCount = 2;
    int assignmentCount = 3;

    // 1. Initialize everything to zero, print to test
    initializeGrades(gradeTable, studentCount, assignmentCount);
    printGradeTable(gradeTable, studentCount, assignmentCount);

    // 2. Hardcode grades for Student 0
    gradeTable[0][0] = 90;
    gradeTable[0][1] = 80;
    gradeTable[0][2] = 70;

    // 3. Hardcode grades for Student 1
    gradeTable[1][0] = 100;
    gradeTable[1][1] = 50;
    gradeTable[1][2] = 75;

    // 4. Print the table
    cout << "Grade Table:\n";
    printGradeTable(gradeTable, studentCount, assignmentCount);

    // 5. Compute averages
    cout << "\nAverages:\n";
    cout << "Student 0 Average: "
         << computeStudentAverage(gradeTable, 0, assignmentCount) << endl;

    cout << "Student 1 Average: "
         << computeStudentAverage(gradeTable, 1, assignmentCount) << endl;

    return 0;
}
