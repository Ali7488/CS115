#include <iostream>
using namespace std;
/*
 */

// this function takes an array, and splits it into a sorted and unsorted region
// returns an ascending order array and uses n(n-1)/2 comparisons
void selectionSort(int arr[], const int &size)
{
    int maxIndex;

    for (int i = size - 1; i > 0; i--) // outer loop for sorted region
    {
        maxIndex = i;               // sets the current max to be i (first field in sorted region)
        for (int j = 0; j < i; j++) // inner loop for unsorted region
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j; // finds largest number and sets that as the max
            }
        }

        // swapping positions in the array
        int temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

// shitty sort, on average n(n-1)/4, worst case n(n-1)/2 comparisons
void insertionSort(int arr[], const int &size)
{
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];                            // key is value we want to swap
        for (j = i; j >= 0 && key < arr[j]; j--) // loops until we find the position where its less than the next value but greater than or equal to the previous
        {
            arr[j + 1] = arr[j]; // shifts everything up until the position we want to the right
        }
        arr[j + 1] = key; // inserts the value we want
    }
}

// if you need me to explain a for loop and if statement, then im sorry you are doomed
//  best case is 1 comparison, worst is n
int linearSearch(const int arr[], const int &size, const int &target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// best case, 1 comparison, average/worst case is log2(n) comparisons
int binarySearch(const int arr[], const int &size, const int &target)
{
    int low = 0, high = size - 1; // sets parameters

    while (low <= high) // if we check every value, exit loop
    {
        int mid = (high + low) / 2; // find mid value
        if (arr[mid] == target)     // target found
        {
            return mid;
        }
        else if (target > arr[mid])
        { // shift low up since we know target is in upper half
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // shift high down since target is in lower half
        }
    }
    return -1;
}
int main()
{
    int data1[] = {7, 3, 9, 1, 5};
    int data2[] = {12, 4, 8, 2, 10, 6};
    const int n1 = sizeof(data1) / sizeof(data1[0]);
    const int n2 = sizeof(data2) / sizeof(data2[0]);

    cout << "Selection sort:\n";
    selectionSort(data1, n1);
    for (int v : data1)
        cout << v << ' ';
    cout << "\n";

    cout << "Insertion sort:\n";
    insertionSort(data2, n2);
    for (int v : data2)
        cout << v << ' ';
    cout << "\n";

    // Both arrays are now sorted ascending; test searches on data2
    cout << "Linear search 8: index " << linearSearch(data2, n2, 8) << "\n";
    cout << "Linear search 99 (absent): index " << linearSearch(data2, n2, 99) << "\n";

    cout << "Binary search 10: index " << binarySearch(data2, n2, 10) << "\n";
    cout << "Binary search 99 (absent): index " << binarySearch(data2, n2, 99) << "\n";

    return 0;
}