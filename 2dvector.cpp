#include <iostream>
using namespace std;

class Vector2D
{
private:
    int x;
    int y;

public:
    Vector2D()
    {
        x = 0;
        y = 0;
    }
    Vector2D(int a, int b)
    {
        x = a;
        y = b;
    }
    int get_x() const
    {
        return x;
    }
    int get_y() const
    {
        return y;
    }
    friend int operator*(const Vector2D &c,const Vector2D &d);
    friend istream &operator>>(istream &input, Vector2D &c);
    friend ostream &operator<<(ostream &output, const Vector2D &c);
};
int operator*(const Vector2D &c, const Vector2D &d)
{
    int new_result =( d.get_x() * c.get_x()) + (d.get_y()* c.get_y());
    return new_result;
}
istream &operator>>(istream &input, Vector2D &c)
{

    cout << "X: ";
    input >> c.x;
    cout << "Y: ";
    input >> c.y;
    return input;
}
ostream &operator<<(ostream &output, const Vector2D &c)
{
    output << "X: ";
    output << c.get_x();
    output << "Y: ";
    output << c.get_y();
    return output;
}
int main()
{
    Vector2D vec1, vec2;
    cout << "Enter first vector coordinates: " << endl;
    cin >> vec1;
    cout << "Enter second vector coordinates: " << endl;
    cin >> vec2;
    cout << "Dot product of the two given vectors is:" << vec1*vec2;
}