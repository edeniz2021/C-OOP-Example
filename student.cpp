/*
Create a class named Student that has three member variables:
name– A string that stores the name of the student
numClasses–An integer that tracks how many courses the student is currently enrolled in
classList–A dynamic array of strings used to store the names of the classes that the student is enrolled in
Write appropriate constructor(s), mutator, and accessor functions for the class
along with the following:
	•A function that inputs all values from the user, including the list of class names.
This function will have to support input for an arbitrary number of classes.
	• A function that outputs the name and list of all courses.
	• A function that resets the number of classes to 0 and the classList to an empty list.
	• An overloaded assignment operator that correctly makes a new copy of the list of courses.
	•A destructor that releases all memory that has been allocated.
*/
#include <iostream>
using namespace std;
class Student
{
private:
    string name;
    int numClases;
    string *classList;

public:
    // constructor
    Student()
    {
    }
    string get_name()
    {
        return name;
    }
    int get_numclass()
    {
        return numClases;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void get_data()
    {
        cout << "Student Name:";
        cin >> name;
        cout << "How many course: ";
        cin >> numClases;
        classList = new string[numClases];
        cout << "Enter " << numClases << " course name: " << endl;
        for (int i = 0; i < numClases; i++)
        {
            cout << i + 1 << ".";
            cin >> classList[i];
        }
    }
    void all_data()
    {
        cout << get_name() << " has enrolled " << get_numclass() << " courses :" << endl;
        for (int i = get_numclass() - 1; i > 0; i--)
        {
            cout << classList[i] << " ,";
            if (i == 1)
            {
                cout << classList[0];
            }
        }
    }
    void reset()
    {
        numClases = 0;
    }
    ~Student()
    {
          delete[] classList;
    }
};

int main()
{
    char a;
    Student cls;
    while (true)
    {
        cls.get_data();
        cls.all_data();
        cout << endl;
        cout << "Do you want to again?y/n: ";
        cin >> a;
        if (a == 'N' || a == 'n')
        {
            break;
        }
        else
            cls.reset();
    }
}