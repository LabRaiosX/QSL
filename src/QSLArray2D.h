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


#ifndef QSL_ARRAY2D_H
#define QSL_ARRAY2D_H

#include <QSLGlobal.h>
#include <QSLArray1D.h>


template<typename Tp>
struct QSLArray2DReturn {
    Tp **data;
    qint rows, cols;
};


template<typename Tp>
class QSLArray2D
{
private:
    //data members
    Tp **mData;
    qint mRows, mCols;
    bool mIsView;

    inline void alloc(qint m, qint n) {
        mRows = m;
        mCols = n;
        mData = new Tp*[m];
        mData[0] = new Tp[m*n];
        for (int i=1; i<m; i++) {
            mData[i] = mData[i-1] + n;
        }
        mIsView = false;
    }

public:

    inline QSLArray2D() : mData(0), mRows(0), mCols(0), mIsView(false) {}
    inline QSLArray2D(qint m, qint n) { alloc(m,n); }
    inline QSLArray2D(const QSLArray2D &other) { mData=0; setView(other); }
    inline QSLArray2D(const QSLArray2DReturn<Tp> &data) { mData=0; *this=data; }
    inline ~QSLArray2D() { free(); }

    inline QSLArray2D& operator = (const QSLArray2D &other) {
        setView(other);
        return *this;
    }

    inline QSLArray2D& operator = (const QSLArray2DReturn<Tp> &data) {
        free();
        mData = data.data;
        mRows = data.rows;
        mCols = data.cols;
        mIsView = false;
        return *this;
    }

    inline Tp* operator [] (qint i) { return mData[i]; }
    inline const Tp* operator [] (qint i) const { return mData[i]; }
    inline const Tp& at(qint i, qint j) const { return mData[i][j]; }

    inline qint rows() const { return mRows; }
    inline qint cols() const { return mCols; }
    inline bool isView() const { return mIsView; }

    inline void setView(const QSLArray2D &other) {
        free();
        mData = other.mData;
        mRows = other.mRows;
        mCols = other.mCols;
        mIsView = true;
    }

    inline void setCopy(const QSLArray2D &other) {
        setSize(other.mRows,other.mCols);
        for (int i=0; i<mRows; i++) {
            for (int j=0; j<mCols; j++) {
                mData[i][j] = other.mData[i][j];
            }
        }
    }

    inline QSLArray2DReturn<Tp> data() {
        QSLArray2DReturn<Tp> ret;
        ret.data = mData;
        ret.rows = mRows;
        ret.cols = mCols;
        mIsView = true;
        return ret;
    }

    inline Tp** pointer() { return mData; }

    inline void setSize(qint m, qint n) {
        #ifndef QSL_NO_DEBUG
        if (mIsView) {
            qDebug() << "QSLArray2D::setSize(): changing size of an array view!";
        }
        #endif
        if (m!=mRows || n!=mCols) {
            free();
            alloc(m,n);
        }
    }

    inline void free() {
        if (!mIsView) {
            if (mData) {
                delete[] mData[0];
                delete[] mData;
            }
        }
    }

    //matrix vector-product
    inline QSLArray1DReturn<Tp> operator * (const QSLArray1D<double> &vec) {
        #ifndef QSL_NO_DEBUG
        if (vec.size()!=mCols) {
            qDebug() << "QSLMath: taking matrix-vector product of improper sizes";
        }
        #endif
        QSLArray1D<double> ret(mRows);
        for (int i=0; i<mRows; i++) {
            ret[i] = 0.0;
            for (int j=0; j<mCols; j++) {
                ret[i] += mData[i][j]*vec[j];
            }
        }
        return ret.data();
    }

    //returns a row as an 1D array
    inline QSLArray1DReturn<Tp> row(qint i) {
        QSLArray1D<double> ret(mCols);
        for (int j=0; j<mCols; j++) {
            ret[j] = mData[i][j];
        }
        return ret.data();
    }

    //returns a column as an 1D array
    inline QSLArray1DReturn<Tp> column(qint i) {
        QSLArray1D<double> ret(mRows);
        for (int j=0; j<mRows; j++) {
            ret[j] = mData[j][i];
        }
        return ret.data();
    }

    void setAll(const Tp &val) {
        for (int i=0; i<mRows; i++) {
            for (int j=0; j<mCols; j++) {
                mData[i][j] = val;
            }
        }
    }

};


#endif //QSL_ARRAY2D_H
