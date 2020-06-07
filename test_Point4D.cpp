#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include "Point4D.h"
using std::cout;
using std::cin;
using std::endl;

/*
Tests class Point4D. Specifically, tests constructors, compound assignment 
operator overloads, basic arithmetic operator overloads, unary +, unary -, 
pre/post-increment/decrement, subscripts, function objects, 
input/output operators, and relational operators.
@return 0 to indicate success.
*/

int main()
{
   const Point4D ZERO;
   // must not compile, because zero is const
   //ZERO[1] = 0;
   //ZERO[2] = 0;
   //ZERO[3] = 0;
   //ZERO[4] = 0;
   const Point4D IDENTITY(1, 0, 1, 0);

   Point4D m1a;                           // default ctor
   cout << "m1a = " << m1a << endl;       // cout << Point4D
   assert( m1a == ZERO);                  // Point4D == Point4D

   Point4D m1b(2);                        // normal ctor with 1 arg
   cout << "m1b = " << m1b << endl;
   assert(m1b == Point4D(2, 0, 0, 0));

   Point4D m1c(2, 3);                     // normal ctor with 2 args
   cout << "m1c = " << m1c << endl;
   assert(m1c == Point4D(2, 3, 0, 0));

   Point4D m1d(2, 3, 8);                  // normal ctor with 3 args
   cout << "m1d = " << m1d << endl;
   assert(m1d == Point4D(2, 3, 8, 0));

   Point4D m1(2.5, 3.6, 8.7, 5.8);                  // normal ctor with 4 args
   Point4D  m1_inverse = m1.inverse();              // inverse, copy ctor

   Point4D m1_inverse_times_m1 = m1_inverse * m1;   // Point4D * Point4D
   assert(m1_inverse_times_m1 == IDENTITY);         // invariant, must hold //

   Point4D m1_times_m1_inverse = m1 * m1_inverse;
   assert(m1_times_m1_inverse == IDENTITY);         // invariant, must hold

   assert(+m1 == -(-m1));                           // +Point4D, -Point4D
   Point4D t1 = m1;
   ++m1;                                            // ++Point4D
   assert(m1 == t1 + 1);
   --m1;                                            // --Point4D
   assert(m1 == t1);

   Point4D m1_post_inc = m1++;                      // Point4D++
   assert(m1_post_inc == t1);
   assert(m1 == t1 + 1);

   Point4D m1_post_dec = m1--;                      // Point4D--
   assert(m1_post_dec == t1 + 1);
   assert(m1 == t1);

   cout << "\n";
   m1d += Point4D(0, 0, 0, 5);                  // Point4D += Point4D
   Point4D m2 = m1d  + 1.0;                       // Point4D = Point4D + int
   assert(m2 == Point4D(3, 4, 9, 6));
   cout << "m2 = " << m2 << endl;

   m2 = 1 + m1d;                                // Point4D = double + Point4D;
   assert(m2 == Point4D(3, 4, 9, 6));

   Point4D m3 = m2 - 1.0;                       // Point4D = Point4D - double
   assert(m3 == m1d);
   cout << "m3 = " << m3 << endl;

   Point4D m4 = 1.0 - m3;                       // Point4D = double - Point4D
   cout << "m4 = " << m4 << endl;
   assert(m4 == Point4D(-1, -2, -7, -4));


   Point4D m5 =  m4 * 2.0 ;                     // Point4D = Point4D * double
   cout << "m5 = " << m5 << endl;
   assert(m5 == Point4D(-2, -4, -14, -8));

   Point4D m6 = -1 *  m5;                    // Point4D = double * Point4D
   cout << "m6 = " << m6 << endl;
   assert(m6 == Point4D(2, 4, 14, 8));
   assert(m6 / -1.0 == m5);                  // Point4D = Point4D / double
   assert(1/m6  == 1*m6.inverse());          // double / Point4D, inverse
   assert(-1.0 * m4  * 2.0 == m6);           // double * Point4D * double

   Point4D m7 = m1++;                        //Point4D++
   cout << "m1 = " << m1 << endl;
   cout << "m7 = " << m7 << endl;
   assert(m7 == m1 - Point4D(1, 1, 1, 1));   // Point4D - Point4D

   Point4D m8 = --m1;                       // --Point4D
   cout << "m1 = " << m1 << endl;
   cout << "m8 = " << m8 << endl;
   assert(m8 == m1 );

   m8--;                                    // Point4D--
   cout << "m8 = " << m8 << endl;
   assert(m1 == 1 + m8);                    // double + Point4D
   assert(m1 - 1 == m8);
   assert(-m1 + 1 == -m8);
   assert(2 * m1 == m8 + m1 + 1);
   assert(m1 * m1 == m1 *(1 + m8));

   Point4D m9(123, 6, 6, 4567.89);
   cout << "m9 = " << m9 << endl;

   // subscripts (non-const)
   m9[1] = 3;
   m9[2] = 1;
   m9[3] = 7;
   m9[4] = 4;
   cout << "m9 = " << m9 << endl;
   assert(m9 == Point4D(3, 1, 7, 4));

   // relational operators
   double smallTol = Point4D::getTolerance() / 10.0;
   Point4D m9Neighbor(3 - smallTol, 1 + smallTol, 7 - smallTol, 4 + smallTol);
   assert(m9 == m9Neighbor);

   double tol = Point4D::getTolerance();
   assert(m9 != (m9 + tol));
   assert(m9 != (m9 + 0.25 * tol));
   assert(m9 == (m9 + 0.15 * tol));
   assert(m9 == m9);

   assert(m9 < (m9 + 0.001));
   assert(m9 <= (m9 + 0.001));
   assert((m9 + 0.001) <= (m9 + 0.001));

   assert((m9 + 0.001) > m9);
   assert((m9 + 0.001) >= m9);
   assert((m9 + 0.001) >= (m9 + 0.001));

   // compound operators

   m9 += m9;
   cout << "m9 = " << m9 << endl;
   assert(m9 == 2 * Point4D(3, 1, 7, 4));

   Point4D m10;
   m10 += (m9 / 2);
   cout << "m10 = " << m10 << endl;
   assert(m10 == Point4D(3, 1, 7, 4));

   m10 *= 2;
   cout << "m10 = " << m10 << endl;
   assert(m10 == m9);

   m10 /= 2;
   cout << "m10 = " << m10 << endl;
   assert(m10 == m9/2);

   m10 += 10;
   cout << "m10 = " << m10 << endl;
   assert(m10 == (m9 +20) / 2);

   m10 -= 10;
   cout << "m10 = " << m10 << endl;
   assert(m10 == 0.5 * m9);

//   testing operator>>
   Point4D input;

   cout << "Please enter the numbers 1.5, 2.5, 3, 4, in that order\n\n";
   cin >> input;
   cout << "input = " << input << endl;

   Point4D diff = input - Point4D(1.5, 2.5, 3, 4);
   assert(diff.absValue() <= tol);    // absolute value
   assert(diff() <= tol);             // function object

   cout << "Test completed successfully!" << endl;
   return 0;
}

