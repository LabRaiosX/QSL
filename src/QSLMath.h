/*
 *  Copyright (C) 2012  Elvis M. Teixeira
 * 
 *  The Q Scientific Library is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 * 
 *  The Q Scientific Library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */


#ifndef QSL_MATH_H
#define QSL_MATH_H

#include "QSLGlobal.h"
#include <qmath.h>


/*!
 * Computes the square of the input
 */
template<typename T> inline T Sqr(const T &x)  { return x*x; }
/*!
 * Computes the second power of the input
 */
template<typename T> inline T Pow2(const T &x) { return x*x; }
/*!
 * Computes the thrird power of the input
 */
template<typename T> inline T Pow3(const T &x) { return x*x*x; }
/*!
 * Computes the fourth power of the input
 */
template<typename T> inline T Pow4(const T &x) { return x*x*x*x; }
/*!
 * Computes the fifth power of the input
 */
template<typename T> inline T Pow5(const T &x) { return x*x*x*x*x; }
/*!
 * Computes the sixth power of the input
 */
template<typename T> inline T Pow6(const T &x) { return x*x*x*x*x*x; }


/*!
 * Sine function
 */
inline double Sin(double x)           { return qSin(x); }
/*!
 * Cossine function
 */
inline double Cos(double x)           { return qCos(x); }
/*!
 * Tangent function
 */
inline double Tan(double x)           { return qTan(x); }
/*!
 * Arc-sine function
 */
inline double Asin(double x)          { return qAsin(x); }
/*!
 * Arc-cossine function
 */
inline double Acos(double x)          { return qAcos(x); }
/*!
 * Arc-tangent function
 */
inline double Atan(double x)          { return qAtan(x); }
/*!
 * Exponential function
 */
inline double Exp(double x)           { return qExp(x); }
/*!
 * Natural logarithm function (base e)
 */
inline double Ln(double x)            { return qLn(x); }
/*!
 * Power function, computes \f[x^y\f], x and y both real
 */
inline double Pow(double x, double y) { return qPow(x,y); }
/*!
 * Square root function (for real numbers)
 */
inline double Sqrt(double x)          { return qSqrt(x); }
/*!
 * Hyperbolic sine function
 */
inline double Sinh(double x)          { return sinh(x); }
/*!
 * Hyperbolic cossine function
 */
inline double Cosh(double x)          { return cosh(x); }


namespace QSL {
    namespace Math {
        /*!
         * Pi, the ratio between a circunference's perimeter and its diameter
         */
        const double Pi              = 3.14159265358979;
        /*!
         * E, the Euler's number, base for natural logarithms
         */
        const double E               = 2.71828182845904;
        /*!
         * Converts an angular measure from degrees to radians
         */
        inline double degToRad(double a) { return a*Pi/180.0; }
        /*!
         * Converts an angular measure from radians to degrees
         */
        inline double radToDeg(double a) { return a*180.0/Pi; }

        inline bool between(double low, double mid, double hig) {
            if ((low<=mid) && (mid<=hig)) {
                return true;
            }
            return false;
        }
    }
}


#endif //QSL_MATH_H
