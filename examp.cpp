#include <iostream>
using namespace std;
typedef int *IntPtr;
void fillArray(int a[], int size)
{
    for(int i = 0; i<size; i++)
    {
        cin >> a[i];
    }
}
// Precondition: size is the size of the array a.
// Postcondition: a[0] through a[size-1] have been
// filled with values read from the keyboard.


int search(int a[], int size, int target)
{
    int coun = -1;
    for(int i = 0;i <size;i++)
    {
        if(a[i]==target)
        {
            coun = i ;  
        }
    }
    if(coun == -1)
    {
        return -1;

    }else return coun ; 
    
}
// Precondition: size is the size of the array a.
// The array elements a[0] through a[size-1] have values.
// If target is in the array, returns the first index of target.
// If target is not in the array, returns -1.
int main()
{
    cout << "This program searches a list of numbers.\n";
    int arraySize;
    cout << "How many numbers will be on the list? ";
    cin >> arraySize;
    IntPtr a;
    a = new int[arraySize];
    fillArray(a, arraySize);
    int target;
    cout << "Enter a value to search for: ";
    cin >> target;
    int location = search(a, arraySize, target);
    if (location == -1)
        cout << target << " is not in the array.\n";
    else
        cout << target << " is element " << location << " in the array.\n";

    delete[] a;
    return 0;
}