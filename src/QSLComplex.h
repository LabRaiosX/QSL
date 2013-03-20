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


#ifndef QSL_COMPLEX_H
#define QSL_COMPLEX_H

#include "QSLMath.h"

QT_BEGIN_NAMESPACE
class QTextStream;
QT_END_NAMESPACE


class QSLComplex
{
private:
     
     double mData[2];
     
public:
     
     inline QSLComplex() {}
     inline QSLComplex(double x, double y) { mData[0]=x; mData[1]=y; }
     inline QSLComplex(double x) { mData[0]=x; mData[1]=0.0; }
     inline QSLComplex(const QSLComplex &z) { mData[0]=z.mData[0]; mData[1]=z.mData[1]; }
     virtual ~QSLComplex() {}
     
     inline QSLComplex& set(double x, double y) { mData[0]=x; mData[1]=y; return *this; }

     inline QSLComplex& setPolar(double r, double theta) {
         mData[0] = r*Cos(theta);
         mData[1] = r*Sin(theta);
         return *this;
     }

     inline QSLComplex conj() const { return QSLComplex(mData[0],-mData[1]); }
     
     inline double& real() { return mData[0]; }
     inline const double& real() const { return mData[0]; }
     inline double& imag() { return mData[1]; }
     inline const double& imag() const { return mData[1]; }
     
     inline double norm() const { return Sqrt(Sqr(mData[0]) + Sqr(mData[1])); }
     inline double normSquared() const { return Sqr(mData[0]) + Sqr(mData[1]); }

     inline double arg() const { return Atan(mData[1]/mData[0]); }
     
     inline QSLComplex& operator = (const QSLComplex &z) {
          mData[0]=z.mData[0]; mData[1]=z.mData[1];
          return *this;
     }
     
     inline QSLComplex& operator = (double x) {
         mData[0]=x; mData[1]=0.0;
         return *this;
     }

     inline bool operator == (const QSLComplex &z) {
          return ((mData[0]==z.mData[0]) && (mData[1]==z.mData[1])) ? true : false;
     }
     
     inline bool operator != (const QSLComplex &z) {
          return ((mData[0]==z.mData[0]) && (mData[1]==z.mData[1])) ? false : true;
     }
     
     inline bool operator == (double x) {
         return ((mData[0]==x) && (mData[1]==0.0)) ? true : false;
     }
     
     inline bool operator != (double x) {
         return ((mData[0]==x) && (mData[1]==0.0)) ? false : true;
     }
     
     inline QSLComplex& operator += (const QSLComplex &z) {
          mData[0] += z.mData[0]; mData[1] += z.mData[1];
          return *this;
     }
     
     inline QSLComplex& operator -= (const QSLComplex &z) {
          mData[0] -= z.mData[0]; mData[1] -= z.mData[1];
          return *this;
     }
     
     inline QSLComplex& operator *= (const QSLComplex &z) {
          mData[0] = mData[0]*z.mData[0] - mData[1]*z.mData[1];
          mData[1] = mData[1]*z.mData[0] + mData[0]*z.mData[1];
          return *this;
     }
     
     inline QSLComplex& operator /= (const QSLComplex &z) {
          double z2 = Sqr(z.mData[0]) + Sqr(z.mData[1]);
          mData[0] = (mData[0]*z.mData[0] + mData[1]*z.mData[1])/z2;
          mData[1] = (mData[1]*z.mData[0] - mData[0]*z.mData[1])/z2;
          return *this;
     }
     
     inline QSLComplex& operator += (double x) {
         mData[0] += x;
         return *this;
     }
     
     inline QSLComplex& operator -= (double x) {
         mData[0] -= x;
         return *this;
     }
     
     inline QSLComplex& operator *= (double x) {
         mData[0] *= x;
         mData[1] *= x;
         return *this;
     }
     
     inline QSLComplex& operator /= (double x) {
         mData[0] /= x;
         mData[1] /= x;
         return *this;
     }
     
     inline QSLComplex operator -() const {
          return QSLComplex(-mData[0],-mData[1]);
     }
     
     inline QSLComplex operator + (const QSLComplex &z) const {
          return QSLComplex(mData[0]+z.mData[0],mData[1]+z.mData[1]);
     }
     
     inline QSLComplex operator - (const QSLComplex &z) const {
          return QSLComplex(mData[0]-z.mData[0],mData[1]-z.mData[1]);
     }
     
     inline QSLComplex operator * (const QSLComplex &z) const {
          return QSLComplex(mData[0]*z.mData[0]-mData[1]*z.mData[1],
                         mData[0]*z.mData[1]+mData[1]*z.mData[0]);
     }
     
     inline QSLComplex operator / (const QSLComplex &z) const {
          double z2 = Sqr(z.mData[0]) + Sqr(z.mData[1]);
          return QSLComplex( (mData[0]*z.mData[0]+mData[1]*z.mData[1])/z2,
                          (mData[1]*z.mData[0]-mData[0]*z.mData[1])/z2 );
     }
     
     inline QSLComplex operator + (double x) const {
          return QSLComplex(mData[0]+x,mData[1]);
     }
     
     inline QSLComplex operator - (double x) const {
          return QSLComplex(mData[0]-x,mData[1]);
     }
     
     inline QSLComplex operator * (double x) const {
          return QSLComplex(mData[0]*x,mData[1]*x);
     }
     
     inline QSLComplex operator / (double x) const {
          return QSLComplex(mData[0]/x,mData[1]/x);
     }
     
     inline friend QSLComplex operator + (double x, const QSLComplex &z) {
          return QSLComplex(x+z.mData[0],z.mData[1]);
     }
     
     inline friend QSLComplex operator - (double x, const QSLComplex &z) {
          return QSLComplex(x-z.mData[0],-z.mData[1]);
     }
     
     inline friend QSLComplex operator * (double x, const QSLComplex &z) {
          return QSLComplex(z.mData[0]*x,z.mData[1]*x);
     }
     
     inline friend QSLComplex operator / (double x, const QSLComplex &z) {
          double z2 = Sqr(z.mData[0]) + Sqr(z.mData[1]);
          return QSLComplex( (x*z.mData[0])/z2,
                          (-x*z.mData[1])/z2 );
     }
     
     /*!
      * Computes the complex exponential of the given complex
      */
     inline friend QSLComplex Exp(const QSLComplex &z) {
          double expx = Exp(z.mData[0]);
          return QSLComplex(expx*Cos(z.mData[1]),expx*Sin(z.mData[1]));
     }

     /*!
      * This function uses the most conventional branch
      * to compute the square root of the given complex
      * number
      */
     inline friend QSLComplex Sqrt(const QSLComplex &z) {
         QSLComplex ret;
         ret.setPolar(Sqrt(z.norm()),z.arg()/2.0);
         return ret;
     }
};


//Imaginary Unity
namespace QSL {
     namespace Math {
          const QSLComplex I(0.0,1.0);
     }
}

//Text Output Stream
inline QTextStream&
operator << (QTextStream &os, const QSLComplex &z) {
     os << "(" << z.real() << "," << z.imag() << ")";
     return os;
}

#ifndef QSL_NO_DEBUG
//Debug output operator
inline QDebug&
operator << (QDebug &debug, const QSLComplex &z) {
    debug << "(" << z.real() << "," << z.imag() << ")";
    return debug;
}
#endif

#endif //QSL_COMPLEX_H
