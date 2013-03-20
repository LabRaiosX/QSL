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


#ifndef QSL_ARRAY1D_H
#define QSL_ARRAY1D_H

#include "QSLGlobal.h"

QT_BEGIN_NAMESPACE
template<typename T> class QVector;
QT_END_NAMESPACE


template<typename Tp>
struct QSLArray1DReturn {
    Tp *data;
    qint size;
};


template<typename Tp>
class QSLArray1D
{
private:
  Tp *mData;
  qint mSize;
  bool mIsView;

  inline void alloc(qint n) {
      mSize = n;
      mData = new Tp[n];
      mIsView = false;
  }

public:

  inline QSLArray1D() : mData(0), mSize(0), mIsView(false) {}
  inline QSLArray1D(qint n) { alloc(n); }
  inline QSLArray1D(const QSLArray1D &other) { mData=0; setView(other); }
  inline QSLArray1D(const QVector<Tp> &qVec) { mData=0; setView(qVec); }
  inline QSLArray1D(const QSLArray1DReturn<Tp> &dat) { mData=0; *this =dat; }
  inline ~QSLArray1D() { free(); }

  inline QSLArray1D& operator = (const QSLArray1D &other) {
      setView(other);
      return *this;
  }

  inline QSLArray1D& operator = (const QVector<Tp> &other) {
      setView(other);
      return *this;
  }

  inline QSLArray1D& operator = (const QSLArray1DReturn<Tp> &data) {
      free();
      mData = data.data;
      mSize = data.size;
      mIsView = false;
      return *this;
  }

  inline Tp& operator [] (qint i) {
      #ifndef QSL_NO_DEBUG
      if (i<0 || i>=mSize) qDebug() << "QSLArray1D: indice out of range!";
      #endif
      return mData[i];
  }

  inline const Tp& operator [] (qint i) const {
    #ifndef QSL_NO_DEBUG
    if (i<0 || i>=mSize) qDebug() << "QSLArray1D: indice out of range!";
    #endif
    return mData[i];
  }

  inline const Tp& at(qint i) const {
    #ifndef QSL_NO_DEBUG
    if (i<0 || i>=mSize) qDebug() << "QSLArray1D: indice out of range!";
    #endif
    return mData[i];
  }

  inline int size() const { return mSize; }
  inline bool isView() const { return mIsView; }

  inline void setView(const QSLArray1D &other) {
      free();
      mData = other.mData;
      mSize = other.mSize;
      mIsView = true;
  }

  inline void setView(const QVector<Tp> &qVec) {
      free();
      mData = const_cast<Tp*> (qVec.data());
      mSize = qVec.size();
      mIsView = true;
  }

  inline void setCopy(const QSLArray1D &other) {
      setSize(other.mSize);
      for (int i=0; i<mSize; i++) {
          mData[i] = other.mData[i];
      }
  }

  inline void setCopy(const QVector<Tp> &qVec) {
      setSize(qVec.size());
      for (int i=0; i<mSize; i++) {
          mData[i] = qVec[i];
      }
  }

  inline QSLArray1DReturn<Tp> data() {
      QSLArray1DReturn<Tp> ret;
      ret.data = mData;
      ret.size = mSize;
      mIsView = true;
      return ret;
  }

  inline Tp* pointer() { return mData; }

  inline void setSize(qint n) {
     #ifndef QSL_NO_DEBUG
     if (mIsView) {
         qDebug() << "QSLArray1D::setSize(): changing size of an array view!";
     }
     #endif
     if (n!=mSize) {
         free();
         alloc(n);
     }
  }

  inline void free() {
      if (!mIsView) {
          if (mData) {
              delete[] mData;
          }
      }
  }

  //dot product
  inline Tp operator * (const QSLArray1D &other) {
      #ifndef QSL_NO_DEBUG
      if (mSize != other.size()) {
          qDebug() << "QSLMath: dot product of arrays of improper sizes";
      }
      #endif
      Tp ret = Tp(0);
      for (int i=0; i<mSize; i++) {
          ret += mData[i]*other.mData[i];
      }
      return ret;
  }

  void setAll(const Tp &val) {
      for (int i=0; i<mSize; i++) {
          mData[i] = val;
      }
  }

};


#endif //QSL_ARRAY1D_H
