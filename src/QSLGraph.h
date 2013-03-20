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


#ifndef QSL_GRAPH_H
#define QSL_GRAPH_H

#include "QSLPlotCartesianSet.h"

class QSL_LIB_DECL QSLGraph : public QSLPlotCartesianSet
{
    Q_OBJECT
public:
    explicit QSLGraph(QObject *parent=0);
    QSLGraph(const QSLArray1D<double> &xArr, const QSLArray1D<double> &yArr, QObject *parent=0);
    QSLGraph(const QVector<double> &xArr, const QVector<double> &yArr, QObject *parent=0);
    virtual ~QSLGraph();
    
private:
    Q_DISABLE_COPY(QSLGraph)
};

#endif // QSL_GRAPH_H
