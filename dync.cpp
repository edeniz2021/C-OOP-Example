/*
One problem with dynamic arrays is that once the array is created using the new operator the size cannot be changed. For example, you might want to add or delete entries from the array similar to the behavior of a vector.

This project asks you to create a class called DynamicStringArray that includes member functions that allow it to emulate the behavior of a vector of strings. The class should have the following:

A private member variable called dynamicArray that references a dynamic array of type string.
A private member variable called size that holds the number of entries in the array.
A default constructor that sets the dynamicArray to NULL and sets size to 0.
A function that returns size.
A function named addEntry that takes a string as input. The function should:
create a new dynamic array one element larger than dynamicArray,
copy all elements from dynamicArray into the new array,
add the new string onto the end of the new array, increment size, delete the old dynamicArray , and then set dynamicArray to the new array.
A function named deleteEntry that takes a string as input. The function should search dynamicArray for the string. If not found, it returns false . If found, the function then:
creates a new dynamic array one element smaller than dynamicArray
copies all elements except the input string into the new array
deletes dynamicArray
decrements size
returns true.
A function named getEntry that takes an integer as input and returns the string at that index in dynamicArray. It should return NULL if the index is out of dynamicArray�s bounds.
A copy constructor that makes a copy of the input object�s dynamic array.
Overload the assignment operator so that the dynamic array is properly copied to the target object.
A destructor that frees up the memory allocated to the dynamic array.
Use the client code below to test your object class.
*/

#include <iostream>
using namespace std;
class DynamicStringArray
{
private:
    int size;
    string *dynamicArray;

public:
    DynamicStringArray()
    {
        size = 0;
        dynamicArray = NULL;
    }
    DynamicStringArray(const DynamicStringArray &d)
    {
        size = d.size;
        dynamicArray = new string[size];
        for (int i = 0; i < size; i++)
        {
            dynamicArray[i] = d.dynamicArray[i];
        }
    }
    ~DynamicStringArray()
    {
        delete[] dynamicArray;
    }
    string get_dynamic_array(int i)
    {
        return dynamicArray[i];
    }
    int get_size() const
    {
        return size;
    }
    void addEntry(string name)
    {
        string *new_string_array = new string[size + 1];
        for (int i = 0; i < size; i++)
        {
            new_string_array[i] = dynamicArray[i];
        }
        new_string_array[size] = name;
        size++;

        delete[] dynamicArray;
        dynamicArray = new_string_array;
    }
    bool deteleEntry(string name)
    {
        int i;
        for (i = 0; i < size; i++)
        {
            if (dynamicArray[i]==name)
            {
                break;
            }
        }
        if (i == size)
        {
            return false;
        }
        int j = 0;
        string *new_string_array = new string[size - 1];
        for (i = 0; i < size; i++)
        {
            if (dynamicArray[i]!=name)
            {
                new_string_array[j++] = dynamicArray[i];
            }
        }
        delete[] dynamicArray;
        size--;
        dynamicArray = new_string_array;
        return true;
    }
    DynamicStringArray operator==(const DynamicStringArray &d)
    {
        size = d.size;
        dynamicArray = new string[size];
        for (int i = 0; i < size; i++)
        {
            dynamicArray[i] = d.dynamicArray[i];
        }
        return d;
    }
};
int main()
{
    char a;
    string b;
    DynamicStringArray arr;

    while (true)
    {
        cout << "Do you want to entry name:";
        cin >> a;
        if (a == 'N' || a == 'n')
        {
            break;
        }
        else
        {
            cout << "Enter name:";
            cin>>b;
            arr.addEntry(b);
            cout << "list name" << endl;
            for (int i = 0; i < arr.get_size(); i++)
            {
                cout << arr.get_dynamic_array(i) << endl;
            }
            cout << endl;
            cout << "Do you want to delete name:";
            cin>>a;
            if (a == 'Y' || a == 'y')
            {
                cout << "Enter delete name:";
                cin>>b;
                arr.deteleEntry(b);
                cout <<endl;
                cout << "New list:"<<endl;
                for (int i = 0; i < arr.get_size(); i++)
            {
                cout << arr.get_dynamic_array(i) << endl;
            }
            }
        }
    }
}