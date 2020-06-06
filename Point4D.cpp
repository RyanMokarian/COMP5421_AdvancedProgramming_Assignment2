#include "Point4D.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using namespace std;

//------> private
double Point4D::tolerance = 1.0E-6;
//------> private ends

//------> public
void Point4D::setTolerance(double tol) { tolerance = std::abs(tol); }
double Point4D::getTolerance() { return tolerance; }
// CONSTRUCTORS (4.3.2 Constructors and Destructor, Pg4, # 2-5)
//default ctor
Point4D::Point4D() : point{ 0,0,0,0 } {} //zero
// normal ctor with 1 arg
Point4D::Point4D(double x1) : point{ x1,0,0,0 } {}
// normal ctor with 2 args
Point4D::Point4D(double x1, double x2) : point{ x1,x2,0,0 } {}
// normal ctor with 3 args
Point4D::Point4D(double x1, double x2, double x3) : point{ x1,x2,x3,0 } {}
// normal ctor with 4 args
Point4D::Point4D(double x1, double x2, double x3, double x4) : point{ x1,x2,x3,x4 } {}
// END OF CONSTRUCTORS (4.3.2)

// 4.3.3 Operator Overloads(Pg 5-6, # 6-14)
// 6. Compound assignment operators.
// Point4D op= Point4D
Point4D& Point4D::operator +=(const Point4D& rhs)
{
    this->point[0] += rhs.point[0];
    this->point[1] += rhs.point[1];
    this->point[2] += rhs.point[2];
    this->point[3] += rhs.point[3];
    return *this;
}
Point4D& Point4D::operator -=(const Point4D& rhs)
{
    this->point[0] -= rhs.point[0];
    this->point[1] -= rhs.point[1];
    this->point[2] -= rhs.point[2];
    this->point[3] -= rhs.point[3];
    return *this;
}
Point4D& Point4D::operator *=(const Point4D& rhs)
{
    Point4D temp = *this;
    this->point[0] = temp.point[0]*rhs.point[0] + temp.point[1]*rhs.point[3]; // x1y1 + x2y4
    this->point[1] = temp.point[0]*rhs.point[1] + temp.point[1]*rhs.point[2]; // x1y2 + x2y3
    this->point[2] = temp.point[3]*rhs.point[1] + temp.point[2]*rhs.point[2]; // x4y2 + x3y3
    this->point[3] = temp.point[3]*rhs.point[0] + temp.point[2]*rhs.point[3]; // x4y1 + x3y4
    return *this;
}
Point4D& Point4D::operator /=(const Point4D& rhs)
{
    Point4D temp = rhs;
    *this *= temp.inverse();
    return *this;
}
// Point4D op= double
Point4D& Point4D::operator +=(double a)
{
    this->point[0] += a;
    this->point[1] += a;
    this->point[2] += a;
    this->point[3] += a;
    return *this;
}
Point4D& Point4D::operator -=(double a)
{
    this->point[0] -= a;
    this->point[1] -= a;
    this->point[2] -= a;
    this->point[3] -= a;
    return *this;
}
Point4D& Point4D::operator *=(double a)
{
    this->point[0] *= a;
    this->point[1] *= a;
    this->point[2] *= a;
    this->point[3] *= a;
    return *this;
}
Point4D& Point4D::operator /=(double a)
{
    if(a==0) {throw invalid_argument("Divide by zero exception");}
    else {
        this->point[0] /= a;
        this->point[1] /= a;
        this->point[2] /= a;
        this->point[3] /= a;
    }
    return *this;
}
// 7. Basic arithmetic operators. (presented later as free functions)
// 8. Relational operators (presented later as free functions)
// 9. Unary operators.
// +X, -X, unary plus/minus
Point4D Point4D::operator +()
{
    return *this;
}
Point4D Point4D::operator -()
{
    double x1 = -point[0];
    double x2 = -point[1];
    double x3 = -point[2];
    double x4 = -point[3];
    return Point4D(x1, x2, x3, x4);
}
// ++X, --X, pre-increment/decrement
Point4D& Point4D::operator ++()
{
    this->point[0] += 1;
    this->point[1] += 1;
    this->point[2] += 1;
    this->point[3] += 1;
    return *this;
}
Point4D& Point4D::operator --()
{
    this->point[0] -= 1;
    this->point[1] -= 1;
    this->point[2] -= 1;
    this->point[3] -= 1;
    return *this;
}
// X++, X--, post-increment/decrement
Point4D Point4D::operator ++(int)
{
    Point4D temp {*this};
    ++(*this);
    return temp;
}
Point4D Point4D::operator --(int)
{
    Point4D temp {*this};
    --(*this);
    return temp;
}
// 10. Subscript operator[] (both const and non-const).
// 11. Function call operator().
// 12. Overloaded extraction (input) operator >>
// 13. Overloaded insertion (output) operator <<
// 14. An absoluteValue()

// public facilitators
// Inversion
Point4D Point4D::inverse() {
    Point4D temp = *this;
    // beta = x1x3 −x2x4
    double beta = temp.point[0] * temp.point[2] - temp.point[1] * temp.point[3];
    if (beta == 0) {throw invalid_argument("Divide by zero exception");}
    else
    {
        // X−1 = beta−1 * [x3, −x2, x1, −x4]
        double x1 = (1/beta) * temp.point[2];
        double x2 = -(1/beta) * temp.point[1];;
        double x3 = (1/beta) * temp.point[0];;
        double x4 = -(1/beta) * temp.point[3];;
        return Point4D(x1, x2, x3, x4);
    }
}
//------> public ends

//------> friends
ostream &operator<<( ostream &output, const Point4D &P ) {
    cout << '[' << P.point[0] << ',' << P.point[1] << ',' << P.point[2] << ',' << P.point[3] << ']';
    return cout;
}
//------> friends end

//------> free functions
// 7. Basic arithmetic operators.
// Point4D op Point4D
Point4D operator +(const Point4D& lhs, const Point4D& rhs)
{
    Point4D temp {lhs};
    temp += rhs;
    return temp;
}
Point4D operator -(const Point4D& lhs, const Point4D& rhs)
{
    Point4D temp {lhs};
    temp -= rhs;
    return temp;
}
Point4D operator *(const Point4D& lhs, const Point4D& rhs)
{
    Point4D temp {lhs};
    temp *= rhs;
    return temp;
}
Point4D operator /(const Point4D& lhs, const Point4D& rhs)
{
    Point4D temp {lhs};
    temp /= rhs;
    return temp;
}
// Point4D op double
Point4D operator +(const Point4D& lhs, const double a)
{
    Point4D temp {lhs};
    temp += a;
    return temp;
}
Point4D operator -(const Point4D& lhs, const double a)
{
    Point4D temp {lhs};
    temp -= a;
    return temp;
}
Point4D operator *(const Point4D& lhs, const double a)
{
    Point4D temp {lhs};
    temp *= a;
    return temp;
}
Point4D operator /(const Point4D& lhs, const double a)
{
    Point4D temp {lhs};
    temp /= a;
    return temp;
}
// double op Point4D
Point4D operator +(const double a, const Point4D& rhs)
{
    Point4D temp {rhs};
    temp += a;
    return temp;
}
Point4D operator -(const double a, const Point4D& rhs)
{
    Point4D temp {rhs};
    temp -= a;
    temp *= -1; // −X = −1 ∗ X
    return temp;
}
Point4D operator *(const double a, const Point4D& rhs)
{
    Point4D temp {rhs};
    temp *= a; // X ∗ a = a ∗ X
    return temp;
}
Point4D operator /(const double a, const Point4D& rhs)
{
    // considering a/X = a∗X−1 and a*X = X*a, we have: a/X = X−1*a
    Point4D temp {rhs};
    Point4D temp_inv = temp.inverse();
    temp_inv *= a;
    return temp_inv; // content of temp_inv is a/X
}
// End of 7. Basic arithmetic operators.

// 8. Relational operators (Point4D op Point4D relational operators)
// equality

bool operator== (const Point4D& x, const Point4D& y) {
    return (abs((x.point[0] - y.point[0])) < x.getTolerance() &&
            abs((x.point[1] - y.point[1])) < x.getTolerance() &&
            abs((x.point[2] - y.point[2])) < x.getTolerance() &&
            abs((x.point[3] - y.point[3])) < x.getTolerance());
}
// X != Y
// X < Y
// X <= Y
// X > Y
// X >= Y
// End of 8. Relational operators
//------> free functions end
