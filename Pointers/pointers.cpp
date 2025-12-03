#include <iostream>
using namespace std;

// ================= Task 1 =================
// pointerBasics()
void pointerBasics()
{
    int x = 5;   // Step 1: declare x
    int *p = &x; // Step 2 & 3: declare p and assign address of x
    *p = 20;     // Step 4: modify x through pointer
}

// ================= Task 2 =================
// modifyValue(int* p)
void modifyValue(int *p)
{
    *p = 999; // change the value at the pointer
}

// ================= Task 3 =================
// printArrayWithPointer(int* arr, int size)
void printArrayWithPointer(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " "; // *(arr+i) == arr[i] for dynamic arrays
    }
}

// ================= Task 4 =================
// sumWithPointerWalk(int* arr, int size)

//* this just shows how to iterate through a dynamic array in a different way as we use p to point to the array
int sumWithPointerWalk(int *arr, int size)
{
    int *p = arr; // pointer walking through array
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total += *p; // add value
        p++;         // move pointer to next element
    }

    return total;
}

// ================= MAIN =================
int main()
{
    // ----- Test pointerBasics -----
    cout << "Testing pointerBasics()...\n";
    pointerBasics();
    cout << "pointerBasics() completed.\n\n";

    // ----- Test modifyValue -----
    cout << "Testing modifyValue()...\n";
    int n = 10;
    cout << "Before modifyValue: n = " << n << endl;
    modifyValue(&n);
    cout << "After modifyValue: n = " << n << endl
         << endl;

    // ----- Test printArrayWithPointer -----
    cout << "Testing printArrayWithPointer()...\n";
    int numbers[5] = {10, 20, 30, 40, 50};
    printArrayWithPointer(numbers, 5);
    cout << endl
         << endl;

    // ----- Test sumWithPointerWalk -----
    cout << "Testing sumWithPointerWalk()...\n";
    int data[5] = {1, 2, 3, 4, 5};
    int total = sumWithPointerWalk(data, 5);
    cout << "Sum returned: " << total << endl;

    return 0;
}
