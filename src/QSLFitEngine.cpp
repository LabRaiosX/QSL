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


#include "QSLFitEngine.h"


QSLFitEngine::QSLFitEngine(QObject *parent)
    :QObject(parent)
{
    mError = 0;
}


QSLFitEngine::QSLFitEngine(const QSLArray1D<double> &xdat,
                           const QSLArray1D<double> &ydat,
                           const QSLArray1D<double> &par,
                           const QSLArray1D<double> &sig,
                           QObject *parent)
    :QObject(parent)
{
    setData(xdat,ydat);
    setParameters(par);
    setSigma(sig);
    setFitAll();
    mError = 0;
}


QSLFitEngine::~QSLFitEngine() {}


int QSLFitEngine::numFitParam() const
{
    int numParamsOn = 0;
    for (int i=0; i<mFitParam.size(); i++) {
        if (mFitParam[i]) numParamsOn += 1;
    }
    return numParamsOn;
}


void QSLFitEngine::setFitParam(int i, bool enabled)
{
    mFitParam[i] = enabled;
}


void QSLFitEngine::setNoSigma()
{
    mSigma.setSize(mX.size());
    for (int i=0; i<mSigma.size(); i++) {
        mSigma[i] = 1.0;
    }
}


void QSLFitEngine::setData(const QSLArray1D<double> &xdat, const QSLArray1D<double> &ydat)
{
#ifndef QSL_NO_DEBUG
    if (xdat.size() != ydat.size()) {
        qDebug() << "QSLFitEngine::setData(): x and y arrays have differents sizes!";
    }
#endif
    mX = xdat;
    mY = ydat;
}


void QSLFitEngine::setParameters(const QSLArray1D<double> &par)
{
    mParam = par;
}


void QSLFitEngine::setSigma(const QSLArray1D<double> &sig)
{
    mSigma = sig;
}


void QSLFitEngine::setFitAll()
{
    mFitParam.setSize(mParam.size());
    for (int i=0; i<mFitParam.size(); i++) {
        mFitParam[i] = true;
    }
}


void QSLFitEngine::solve() {}
double QSLFitEngine::evalChiSquare() const { return 0.0; }


//QSLFitEngine.cpp
