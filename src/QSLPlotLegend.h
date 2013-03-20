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


#ifndef QSL_PLOTLEGEND_H
#define QSL_PLOTLEGEND_H

#include "QSLPlotable.h"

class QPainter;


class QSL_LIB_DECL QSLPlotLegend : public QSLPlotable
{
    Q_OBJECT
public:
    explicit QSLPlotLegend(QObject *parent = 0);
    
    virtual void draw(QPainter *painter, QFontMetrics *fontMetrics, const QList<QSLPlotable*> &plts, int x, int y);
    
};

#endif // QSL_PLOTLEGEND_H
