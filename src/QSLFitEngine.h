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


#ifndef QSL_FITENGINE_H
#define QSL_FITENGINE_H

#include "QSLGlobal.h"
#include "QSLArray1D.h"


class QSLFitEngine : public QObject
{
    Q_OBJECT
public:
    QSLFitEngine(QObject *parent=0);

    QSLFitEngine(const QSLArray1D<double> &xdat,
                 const QSLArray1D<double> &ydat,
                 const QSLArray1D<double> &par,
                 const QSLArray1D<double> &sig,
                 QObject *parent=0);

    virtual ~QSLFitEngine();

    QSLArray1D<double> &x() { return mX; }
    QSLArray1D<double> &y() { return mY; }
    QSLArray1D<double> &param() { return mParam; }
    QSLArray1D<double> &sigma() { return mSigma; }
    double x(int i) const { return mX[i]; }
    double y(int i) const { return mY[i]; }
    double param(int i) const { return mParam[i]; }
    double sigma(int i) const { return mSigma[i]; }
    int numParam() const { return mParam.size(); }
    int numFitParam() const;
    int numPts() const { return mX.size(); }
    bool fitParam(int i) { return mFitParam[i]; }
    double chiSqr() const { return mChiSq; }
    int error() { return mError; }

    virtual double evalChiSquare() const;
    
signals:
    void errorOcurred();
    void sucessfulSolved();
    
public slots:
    virtual void solve();
    void setFitParam(int i, bool enabled);
    void setNoSigma();
    virtual void setData(const QSLArray1D<double> &xdat, const QSLArray1D<double> &ydat);
    virtual void setParameters(const QSLArray1D<double> &par);
    virtual void setSigma(const QSLArray1D<double> &sig);
    void setFitAll();
    
protected:
    QSLArray1D<double> mX, mY;
    QSLArray1D<double> mSigma;
    QSLArray1D<double> mParam;
    QSLArray1D<bool> mFitParam;
    double mChiSq;
    int mError;
};


#endif //QSL_FITLINE_H
