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


#ifndef QSL_FITLINE_H
#define QSL_FITLINE_H

#include "QSLFitEngine.h"

class QSLFitLine : public QSLFitEngine
{
    Q_OBJECT
public:
    explicit QSLFitLine(QObject *parent = 0);

    QSLFitLine(const QSLArray1D<double> &xdat,
               const QSLArray1D<double> &ydat,
               const QSLArray1D<double> &par,
               const QSLArray1D<double> &sig,
               QObject *parent=0);

    virtual ~QSLFitLine();

    virtual double evalChiSquare() const;

public slots:
    virtual void solve();

protected:
    double mS, mSx, mSxx, mSy, mSxy;
};

#endif // QSL_FITLINE_H
