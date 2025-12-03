#include <iostream>
#include <string>
using namespace std;

/*
!THIS IS CONTINUED FROM THE POINTERS FILES, THIS USES ALL POINTER CONCEPTS
this covers dynamic arrays, how to resize them, how to handle memory to ensure no leaks
*/

// this shows the basics of dynamic memory, we created a pointer that holds ONE int in it called ptr
// we used *ptr to set the value stored in the heap to 20 then printed it
//!! for every new you use, we must also have a delete for it to free the memory
void dynamicBasics()
{
    int *ptr = new int;
    *ptr = 20;
    cout << *ptr;
    delete ptr;
    ptr = nullptr;
}

// here we created a dynamic array, added values to it, printed values, then free'd the memory with delete[]
// note you must set it to nullptr after to avoid errors
void allocateArray()
{
    int *arr = new int[10]; //* here i hard-coded 10, but it could be any int variable e.g. size
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
        cout << arr[i] << " ";
    }

    delete[] arr;
    arr = nullptr;
}
// here we are showing how to change the size of the array if we need it
// we create a NEW array, copy all the data from old to new, then delete the old
// afterwards we set the old pointer = to the new pointer so now they both point to the same area in the heap
// aka calling arr and newArr right now would do the same thing (but we dont use newArr rn because it will be changed)
//* note that after we copy, there will be random numbers printed, thats fine since the task didnt ask us to set it to 0, if we needed to set it to 0 then we would have just used another for loop
void resizeArray(int *&arr, int &size)
{
    int newSize = size + 3;

    int *newArr = new int[newSize];

    for (int i = 0; i < size; i++) //! note must be less than size not newSize or we get an outofbounds error
    {
        newArr[i] = arr[i];
    }
    size = newSize;
    delete[] arr;
    arr = newArr;
}

void addValue(int *&arr, int &size, int &capacity, int value)
{
    if (size >= capacity)
    {
        int newCapacity = capacity * 2;
        int *newArr = new int[newCapacity];

        for (int i = 0; i < capacity; i++)
        {
            newArr[i] = arr[i];
        }
        capacity = newCapacity;
        delete[] arr;
        arr = newArr;
    }
    arr[size] = value;
    size++;
}

// tests for the functions
int main()
{
    // ===== Task 1: dynamicBasics =====
    cout << "Testing dynamicBasics()...\n";
    dynamicBasics();
    cout << "dynamicBasics() complete.\n\n";

    // ===== Task 2: allocateArray =====
    cout << "Testing allocateArray()...\n";
    allocateArray();
    cout << "allocateArray() complete.\n\n";

    // ===== Task 3: resizeArray =====
    cout << "Testing resizeArray()...\n";
    int size = 5;
    int *arr = new int[size];

    // Fill initial array
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1; // 1 2 3 4 5
    }

    cout << "Before resize: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    resizeArray(arr, size); // Should increase size

    cout << "After resize: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    // ===== Task 4: addValue =====
    cout << "Testing addValue()...\n";

    int capacity = 5; // initial capacity
    int *list = new int[capacity];
    int listSize = 0;

    // Add some elements to trigger expansion
    addValue(list, listSize, capacity, 10);
    addValue(list, listSize, capacity, 20);
    addValue(list, listSize, capacity, 30);
    addValue(list, listSize, capacity, 40);
    addValue(list, listSize, capacity, 50);
    addValue(list, listSize, capacity, 60); // this one should cause resize

    cout << "List contents: ";
    for (int i = 0; i < listSize; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    cout << "Final size = " << listSize << endl;
    cout << "Final capacity = " << capacity << endl;

    delete[] arr;
    delete[] list;

    return 0;
}
