/*Define a class for a type called Circle . An object of type Circle is used to display
the area, diameter, and circumference of a circle based on the radius of that object.
Include a mutator function that sets the radius to a value given as an argument.
Include member function to calculate the area, diameter, and circumference of the
circle. Also include a member function that returns the radius of the circle. Embed
your class definition in a test program.*/
#include <iostream>
#define pi 3.14

using namespace std;


class MyCircle
{
  public:
    MyCircle(){
    void setRadius();
    void  getRadius();
    }
    void setRadius()
{
    cout<<"how much radius?"<<endl;
    cin >> radius ; 
    radius = radius;
    cout << endl;
}
   double getArea()
{   
    area= pi* radius * radius ; 
    return area;
    
}
    double getCircum()
{   
    circum= pi* radius * 2 ; 
    return circum;
    
}
  private:
    double radius;
    double area;
    double circum;

};


int main()
{
    MyCircle circle;
    circle.setRadius();
   cout<< "Circle circum:"<<circle.getCircum()<<endl;
   cout<< "Circle area:"<< circle.getArea();
  
    return 0;
}
