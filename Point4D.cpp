#include "Point4D.h"
#include <iostream>
#include <math.h>
using namespace std;

//------> private
double Point4D::tolerance = 1.0E-6;
void Point4D::setTolerance(double tol) { tolerance = std::abs(tol); }
double Point4D::getTolerance() { return tolerance; }
//------> private ends

//------> public
// CONSTRUCTORS
// 4 elements constructor
Point4D::Point4D(double x1, double x2, double x3, double x4) {
    point[0] = x1;
    point[1] = x2;
    point[2] = x3;
    point[3] = x4;
 }

//default constructor
Point4D::Point4D() : point{ 0,0,0,0 } {} //zero
//first element constructor
Point4D::Point4D(double x) : point{ x,0,0,0 } {}
// END OF CONSTRUCTORS

//------> public ends

//------> friends
ostream &operator<<( ostream &output, const Point4D &P ) {
    cout << '[' << P.point[0] << ',' << P.point[1] << ',' << P.point[2] << ',' << P.point[3] << ']';
    return cout;
}
//------> friends end

//------> free functions (Point4D op Point4D relational operators)
// equality
bool operator== (const Point4D& x, const Point4D& y) {
    return ((x.point[0] == y.point[0]) &&
            (x.point[1] == y.point[1]) &&
            (x.point[2] == y.point[2]) &&
            (x.point[3] == y.point[3]));
}
// X != Y
// X < Y
// X <= Y
// X > Y
// X >= Y
//------> free functions end
