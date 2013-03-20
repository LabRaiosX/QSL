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


#include "QSLFitLine.h"
#include "QSLMath.h"


QSLFitLine::QSLFitLine(QObject *parent) :
    QSLFitEngine(parent)
{
}


QSLFitLine::QSLFitLine(const QSLArray1D<double> &xdat,
                       const QSLArray1D<double> &ydat,
                       const QSLArray1D<double> &par,
                       const QSLArray1D<double> &sig,
                       QObject *parent)
    :QSLFitEngine(parent)
{
    setData(xdat,ydat);
    setParameters(par);
    setSigma(sig);
    setFitAll();
    mError = 0;
}


QSLFitLine::~QSLFitLine() {}


void QSLFitLine::solve()
{
    mS = 0.0;
    mSx = 0.0;
    mSxx = 0.0;
    mSy = 0.0;
    mSxy = 0.0;
    for (int i=0; i<mX.size(); i++) {
        double sigsq = Sqr(mSigma[i]);
        mS += sigsq;
        mSx += mX[i]/sigsq;
        mSxx += Sqr(mX[i])/sigsq;
        mSy += mY[i]/sigsq;
        mSxy += mX[i]*mY[i]/sigsq;
    }
    double delta = mS*mSxx - Sqr(mSx);
    mParam[0] = (mSxx*mSy - mSx*mSxy) /delta;
    mParam[1] = (mS*mSxy - mSx*mSy) /delta;
}


double QSLFitLine::evalChiSquare() const
{
    double chi2 = 0.0;
    for (int i=0; i<mX.size(); i++) {
        double fi = mParam[0] + mParam[1]*mX[i];
        chi2 += Sqr((fi - mY[i])/mSigma[i]);
    }
    return chi2;
}


//QSLFitLine.cpp
