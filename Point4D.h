#ifndef POINT4D_H
#define POINT4D_H

#include <iostream>
#include <array>
using namespace std;


class Point4D {

//------> private
private:
    static double tolerance;
    static void setTolerance(double tol);
    static double getTolerance();
//------> private ends

//------> public
public:
    array<double, 4> point;

    explicit Point4D(double, double, double, double); // constructor
    Point4D(); //default constructor
    Point4D(double);//first element constructor

//------> public ends

//------> friends
    friend ostream &operator<<(ostream &output, const Point4D &P);
//------> friends end

};//---->END OF CLASS

//------> free functions (Point4D op Point4D relational operators)
bool operator== (const Point4D& x, const Point4D& y); // equality
// X != Y
// X < Y
// X <= Y
// X > Y
// X >= Y
//------> free functions end

#endif //POINT4D_H
