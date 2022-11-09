/*Define a class for rational numbers. A rational number is a number that can be
represented as the quotient of two integers. For example, 1/2, 3/4, 64/2, and so
forth are all rational numbers. (By 1/2 and so on we mean the everyday ­fraction,
not the integer division this expression would produce in a C++ program.)
Represent rational numbers as two values of type int , one for the numerator and
one for the denominator. Call the class Rational . Include a constructor with
two arguments that can be used to set the member variables of an object to any
legitimate values. Also include a constructor that has only a single parameter of
type int ; call this single parameter wholeNumber and define the constructor so
that the object will be initialized to the rational number wholeNumber /1. Include
a default constructor that initializes an object to 0 (that is, to 0/1). Overload
the input and output operators >> and << . Numbers are to be input and output
in the form 1/2 , 15/32 , 300/401 , and so forth. Note that the numerator, the
denominator, or both may contain a minus sign, so −1/2 , 15/−32 , and −300/−401
are also possible inputs. Overload all the following operators so that they correctly
apply to the type R ­ ational : == , < , <= , > , >= , + , − , * , and / . Write a test program
to test your class. Hints: Two rational numbers a/b and c/d are equal if a*d equals
c*b. If b and d are positive rational numbers, a/b is less than c/d provided a*d
is less than c*b. You should include a function to normalize the values stored
so that, after normalization, the denominator is positive and the numerator and
denominator are as small as possible. For example, after normalization 4/-8 would
be represented the same as −1/2 .*/
#include <iostream>
#include <cmath>
using namespace std;

class Rational
{
private:
    int numinator;
    int deminator;

public:
    Rational(int wholeNumber)
    {
        numinator = wholeNumber;
        deminator = 1;
    }
    Rational()
    {
        numinator = 0;
        deminator = 1;
    }
    Rational(int num, int dem)
    {
        numinator = num;
        deminator = dem;
    }
    int get_numinator() const
    {
        return numinator;
    }
    int get_deminator() const
    {
        return deminator;
    }

    Rational normalize()
    {

        Rational temp;
        int x, y, z;
        x = numinator;
        y = deminator;
        z = (x * x < y * y) ? (z = x) : (z = y);

        for (int i = 2; i * i <= z * z; i++)
        {
            while ((x % i) == 0 && (y % i) == 0)
            {

                x = x / i;
                y = y / i;
                z = z / i;
            }
        }

        if (y < 0)
        {
            temp.numinator = -x;
            temp.deminator = -y;
        }
        else
        {
            temp.numinator = x;
            temp.deminator = y;
        }

        return temp;
    }
    Rational operator*(const Rational &c)
    {
        int new_numinator = numinator * c.get_numinator();
        int new_deminator = deminator * c.get_deminator();
        return Rational(new_numinator, new_deminator);
    }
    Rational operator/(const Rational &c)
    {
        int new_numinator = numinator * c.get_deminator();
        int new_deminator = deminator * c.get_numinator();
        return Rational(new_numinator, new_deminator);
    }

    Rational operator+(const Rational &c)
    {
        int new_numinator = (numinator * c.get_deminator()) + (deminator * c.get_numinator());
        int new_deminator = deminator * c.get_deminator();

        return Rational(new_numinator, new_deminator);
    }
    Rational operator-(const Rational &c)
    {
        int new_numinator = (numinator * c.get_deminator()) - (deminator * c.get_numinator());
        int new_deminator = deminator * c.get_deminator();

        return Rational(new_numinator, new_deminator);
    }
    bool operator>(const Rational &c)
    {
        return ((numinator * c.deminator) > (deminator * c.numinator));
    }
    bool operator<(const Rational &c)
    {
        return ((numinator * c.deminator) < (deminator * c.numinator));
    }
    friend istream &operator>>(istream &input, Rational &c);
    friend ostream &operator>>(ostream &output, const Rational &c);
};
istream &operator>>(istream &input, Rational &c)
{
    input >> c.numinator;
    cout << "/";
    input >> c.deminator;
    return input;
}
ostream &operator<<(ostream &output, const Rational &c)
{
    output << c.get_numinator() << "/" << c.get_deminator() << endl;
    return output;
}
int main()
{
    Rational rat1;
    Rational rat2;
    Rational result;
    cout << "Enter the first value : " << endl;
    cin >> rat1;
    cout << "Enter the second value : " << endl;
    cin >> rat2;
    cout << "Value1 is :";
    cout << rat1;
    cout << "Normalized : " << rat1.normalize() << endl;
    cout << "Value2 is: ";
    cout << rat2;
    cout << "Normalized : " << rat2.normalize() << endl;
    cout << "Addition: ";
    result = rat1 + rat2;
    cout << result;
    cout << "Normalized : " << result.normalize() << endl;
    cout << "Subtraction: ";
    result = rat1 - rat2;
    cout << result;
    cout << "Normalized : " << result.normalize() << endl;
    cout << "Multiplication: ";
    result = rat1 * rat2;
    cout << result;
    cout << "Normalized : " << result.normalize() << endl;
    cout << "Division : ";
    result = rat1 / rat2;
    cout << result;
    cout << "Normalized : " << result.normalize() << endl;
    cout << "Is " << rat1 << ">" << rat2 << "?" << ((rat1 > (rat2))? "yes" : "no") << endl;
    cout << "Is " << rat1 << "<" << rat2 << "?" << ((rat1 < (rat2))? "yes" : "no") << endl;
}
