/*Define a class for complex numbers. A complex number is a number of the form
a + b*i
		 where for our purposes, a and b are numbers of type double , and i is a number
that represents the quantity 1- 1. Represent a complex number as two valuesProgramming Projects     
of type double . Name the member variables real and imaginary . (The variable
for the number that is multiplied by i is the one called imaginary .) Call the class
Complex . Include a constructor with two parameters of type double that can be
used to set the member variables of an object to any values. Include a construc-
tor that has only a single parameter of type double ; call this parameter realPart
and define the constructor so that the object will be initialized to realPart + 0* i.
Include a default constructor that initializes an object to 0 (that is, to 0 + 0* i).
Overload all the following operators so that they correctly apply to the type
­ Complex : == , + , − , *, >> , and << . You should also write a test program to test your
class. Hints: To add or subtract two complex numbers, add or subtract the two
member variables of type double . The product of two complex numbers is given
by the following formula:
(a + b * i) * (c + d * i) = = (a * c - b * d ) + (a * d + b * c) * i
		 In the interface file, you should define a constant i as follows:
const Complex i(0, 1);
This defined constant i will be the same as the i discussed above.*/

#include <iostream>
using namespace std;

class Complex
{
private:
	double real;
	double imag;

public:
	Complex(int r, int i)
	{
		real = r;
		imag = i;
	}
	Complex()
	{
	}
	friend ostream &operator<<(ostream &outputStream, const Complex &obj);
	friend istream &operator>>(istream &inputStream, Complex &obj);
	const Complex operator+(const Complex &obj) const
	{

		int final_real = real + obj.real;
		int final_imag = imag + obj.imag;
		return Complex(final_real, final_imag);
	}
	const Complex operator-(const Complex &obj) const
	{
		int final_real = real - obj.real;
		int final_imag = imag - obj.imag;
		return Complex(final_real, final_imag);
	}
	const Complex operator*(const Complex &obj) const
	{
		int final_real = (real * obj.real) - (imag * obj.imag);
		int final_imag = (real * obj.imag) + (obj.real * imag);
		return Complex(final_real, final_imag);
	}
	const bool operator==(const Complex &obj) const
	{
		return (real == obj.real && imag == obj.imag);
	}
};
ostream &operator<<(ostream &outputStream, const Complex &obj)
{
	outputStream << obj.real << " + " << obj.imag << "i" << endl;
	return outputStream;
}
istream &operator>>(istream &inputStream, Complex &obj)
{
	inputStream >> obj.real;
	inputStream >> obj.imag;
	return inputStream;
}

int main()
{
	Complex c1;
	Complex c2(7, 8), result;
	cout << "Enter real and imag" << endl;
	cin >> c1;
	cout << "Complex Number 1: ";
	cout << c1;
	cout << "Complex Number 2: ";
	cout << c2;
	result = c1 + c2;
	cout << "Addition ";
	cout << result;
	result = c1 - c2;
	cout << "Subtraction ";
	cout << result;
	result = c1 * c2;
	cout << "Multiplication ";
	cout << result;

	if (c1 == c2)
	{
		cout << "same real numbers" << endl;
	}
	return 0;
}