/*
The type Point is a fairly simple data type, but under another name (the template
class pair ) this data type is defined and used in the C++ Standard Template Li-
brary, although you need not know anything about the Standard Template Library
to do this exercise. Write a definition of a class named Point that might be used to
store and manipulate the location of a point in the plane. You will need to declare
and implement the following member functions:
 a.	A member function set that sets the private data after an object of this class is
created.
b.	A member function to move the point by an amount along the vertical and
horizontal directions specified by the first and second arguments.
c.	A member function to rotate the point by 90 degrees clockwise around the
origin.
d. Two const inspector functions to retrieve the current coordinates of the point.*/
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    public:
    Point()
    {
        void set_x();
        void set_y();
        void get_X_Y();

    }
    void set_x()
    {
        cout << "How many x ?" << endl;
        cin >> x ; 
        cout << endl;
    }
    void set_y()
    {
        cout << "How many y ?" << endl;
        cin >> y ; 
        cout << endl;
    }
    int get_X() const
    {
    return x;
    }
    int get_Y() const
    {
    return y;
    }
    void get_X_Y()
    {
        cout <<"{x,y}" <<"="<<"{"<<x<< ","<<y<<"}"<<endl;
    }
    void rotate_90(Point p)
    {
        int new_x;
        int new_y;
        new_x = (p.get_Y());
        new_y = -(p.get_X());
        cout << "Your point 90 degree rotate is: ";
        print(new_x,new_y);
    }
    void print(int a,int b)
    {
        cout <<"{x,y}" <<"="<<"{"<<a<< ","<<b<<"}"<<endl;
        
    }
    int increase_horizontal(int k)
    {
        x = x + k ;
        return x;
    }
    int increase_vertical(int k)
    {
        y = y + k;
        return y;
    }
    bool question_x()
    {
        cout << "do you want to horizontal increase?Y/N"<<endl;
        cin>> answer;
        if(answer=='Y' || answer=='y')
        {
            return true;
        }else return false;
    }
    void implement_increase_x()
    {
       
        if((question_x())==true)
        {
           cout << "How much increase?"<<endl;
         cin>> increase; 
            increase_horizontal(increase);
cout <<"{x,y}" <<"="<<"{"<<x<< ","<<y<<"}"<<endl;
        }else cout <<"{x,y}" <<"="<<"{"<<x<< ","<<y<<"}"<<endl;;
        
    }
     bool question_y()
    {
        cout << "Do you want to vertical increase?Y/N"<<endl;
        cin>> answer;
        if(answer=='Y' || answer=='y')
        {
            return true;
        }else return false;
    }
    void implement_increase_y()
    {
       
        if((question_y())==true)
        {
           cout << "How much increase?"<<endl;
         cin>> increase; 
            increase_vertical(increase);
cout <<"{x,y}" <<"="<<"{"<<x<< ","<<y<<"}"<<endl;
        }else cout <<"{x,y}" <<"="<<"{"<<x<< ","<<y<<"}"<<endl;  
    }
    
    private:
    int x;
    int y;
    char answer;
    int increase;
};
Point p;
int main()
{
    p.set_x();
    p.set_y();
    p.get_X_Y();
    p.implement_increase_x();
    p.implement_increase_y();
    p.rotate_90(p);

}
/*
http://creativeworks.lol/storytelling-number-one-skill-improve/ */
/*
#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
Point(double initial_x = 0, double initial_y = 0);
void shift(double x_amount, double y_amount);
void rotate90();
int rotation_needed(Point p);
void rotation_upper_right(Point &p);

double get_x() const {return x;}
double get_y() const {return y;}

friend istream& operator >>(istream &ins, Point &target);

private:
double x;
double y;
};

//NON-MEMBER FUNCTIONS
double distance(const Point &p1, const Point &p2);
Point mid_point(const Point &p1, const Point &p2);
bool operator ==(const Point &p1, const Point &p2);
bool operator !=(const Point &p1, const Point &p2);
Point operator +(const Point &p1, const Point &p2);
ostream& operator <<(ostream &outs, const Point &source);


Point::Point(double initial_x, double initial_y)
{
x = initial_x;
y = initial_y;
}

void Point::shift(double x_amount, double y_amount)
{
x += x_amount;
y += y_amount;
}

void Point::rotate90()
{
double new_x;
double new_y;

new_x = y;
new_y = -x;
x = new_x;
y = new_y;
}

int Point::rotation_needed(Point p)
{
int answer = 0;
while((p.get_x() < 0) || (p.get_y() < 0))
{
p.rotate90();
answer++;
}
return answer;
}

void Point::rotation_upper_right(Point &p)
{
while((p.get_x() < 0) || (p.get_y() < 0))
{
p.rotate90();
}
}

double distance(const Point &p1,const Point &p2)
{
double a, b, c_square;
a = p1.get_x() - p2.get_x();
b = p1.get_y() - p2.get_y();
c_square = a*a + b*b;

return (sqrt(c_square));
}

Point mid_point(const Point& p1, const Point& p2)
{
double x_midpoint, y_midpoint;

x_midpoint = (p1.get_x() + p2.get_x()) / 2;
y_midpoint = (p1.get_y() + p2.get_y()) / 2;

Point midpoint(x_midpoint, y_midpoint);
//construct new object midpoint with values of x_midpoint and y_midpoint

return midpoint;
}

bool operator ==(const Point &p1, const Point &p2)
{
return ((p1.get_x() == p2.get_x()) && (p1.get_y() == p2.get_y()));
}

bool operator !=(const Point &p1, const Point &p2)
{
return (!(p1 == p2));
}

Point operator +(const Point &p1, const Point &p2)
{
double x_sum, y_sum;
x_sum = p1.get_x() + p2.get_x();
y_sum = p1.get_y() + p2.get_y();

Point sum(x_sum, y_sum);
return sum;
}

ostream& operator <<(ostream &outs, const Point &source)
{
outs << source.get_x() << " " << source.get_y();
return outs;
}

istream& operator >>(istream &ins, Point &target)
{
ins >> target.x >> target.y;
return ins;
}*/
