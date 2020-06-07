#ifndef POINT4D_H
#define POINT4D_H

#include <iostream>
#include <array>
using namespace std;


class Point4D {

//------> private
private:
// 4.3.1 Static Member Deﬁnitions
    static double tolerance;
//------> private ends

//------> public
public:
    array<double, 4> point;
    static void setTolerance(double tol);
    static double getTolerance();
// CONSTRUCTORS (4.3.2 Constructors and Destructor, Pg4, # 2-5)
    Point4D(); // default ctor
    Point4D(double);// normal ctor with 1 arg
    Point4D(double, double);// normal ctor with 2 args
    Point4D(double, double, double);// normal ctor with 3 args
    explicit Point4D(double, double, double, double); // 2. normal ctor with 4 args
    // BIG 3
    Point4D(const Point4D&) = default; // 3. Defaulted copy constructor
    Point4D& operator=(const Point4D&) = default; // 4. Defaulted assignment operator
    virtual ~Point4D() = default; // 5. Defaulted destructor
    // END OF BIG 3
// END OF CONSTRUCTORS (4.3.2)

// 4.3.3 Operator Overloads (Pg 5-6, # 6-14)
// 6. Compound assignment operators.
// Point4D op= Point4D
    Point4D& operator +=(const Point4D& rhs);
    Point4D& operator -=(const Point4D& rhs);
    Point4D& operator *=(const Point4D& rhs);
    Point4D& operator /=(const Point4D& rhs);
// Point4D op= double
    Point4D& operator +=(double);
    Point4D& operator -=(double);
    Point4D& operator *=(double);
    Point4D& operator /=(double);
// 7. Basic arithmetic operators (presented later as free functions)
// 8. Relational operators (presented later as free functions)
// 9. Unary operators.
// +X, -X, unary plus/minus
    Point4D operator +();
    Point4D operator -();
// ++X, --X, pre-increment/decrement
    Point4D& operator ++();
    Point4D& operator --();
// X++, X--, post-increment/decrement
    Point4D operator ++(int);
    Point4D operator --(int);
// 10. Subscript operator[] (both const and non-const).
    double& operator [](unsigned int);
    const double& operator [](unsigned int) const;
// 11. Function call operator().
// 12. Overloaded extraction (input) operator >>  // make an input validation
// 13. Overloaded insertion (output) operator <<
// 14. An absoluteValue()

// public facilitators
// Inversion
    Point4D inverse();

//------> public ends

//------> friends
    friend ostream &operator<<(ostream &output, const Point4D &P);
//------> friends end

};//---->END OF CLASS

//------> free functions
// 7. Basic arithmetic operators
// Point4D op Point4D
Point4D operator +(const Point4D& lhs, const Point4D& rhs);
Point4D operator -(const Point4D& lhs, const Point4D& rhs);
Point4D operator *(const Point4D& lhs, const Point4D& rhs);
Point4D operator /(const Point4D& lhs, const Point4D& rhs);
// Point4D op double
Point4D operator +(const Point4D& lhs, const double);
Point4D operator -(const Point4D& lhs, const double);
Point4D operator *(const Point4D& lhs, const double);
Point4D operator /(const Point4D& lhs, const double);
// double op Point4D
Point4D operator +(const double, const Point4D& rhs);
Point4D operator -(const double, const Point4D& rhs);
Point4D operator *(const double, const Point4D& rhs);
Point4D operator /(const double, const Point4D& rhs);
// 8. Relational operators (Point4D op Point4D relational operators)
bool operator== (const Point4D& x, const Point4D& y); // equality
// X != Y
// X < Y
// X <= Y
// X > Y
// X >= Y
//------> free functions end

#endif //POINT4D_H
