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


#include "QSLPlotLegend.h"
#include <QPainter>
#include <QSLPlotCartesianSet.h>

QSLPlotLegend::QSLPlotLegend(QObject *parent)
    : QSLPlotable(parent)
{
    mTitle = "Legend";
}


void QSLPlotLegend::draw(QPainter *painter,
                         QFontMetrics *fontMetrics,
                         const QList<QSLPlotable *> &plts,
                         int x, int y)
{
    if (!mVisible) return;
    painter->save();

    for (int i=0; i<plts.size(); i++) {
        QSLPlotCartesianSet *plt = static_cast<QSLPlotCartesianSet*> (plts.at(i));
        
        int r;
        bool hasThumb = plt->drawPoints() && plt->hasThumbLegend();
        if (hasThumb) {
            r = plt->pointRadius();
        } else {
            r = 0;
        }

        painter->setPen(plt->pen());
        painter->setBrush(plt->brush());

        QString text = plt->title();
        int textWidth = fontMetrics->width(text);
        int textHeight = fontMetrics->height();

        int xi = x -4*r;
        int yi = y + i*(textHeight +3*r);

        if (hasThumb && plt->drawLine()) {
            painter->drawLine( xi-4*r, yi, xi+4*r, yi);
        }

        if (hasThumb) {
            QPolygon polygon;
            switch (plt->pointStyle())
            {
                case QSLPlotCartesianSet::Circles:
                    painter->setBrush(Qt::NoBrush);
                    painter->drawEllipse( xi-r, yi-r, 2*r, 2*r);
                    break;

                case QSLPlotCartesianSet::FullCircles:
                    painter->drawEllipse( xi-r, yi-r, 2*r, 2*r);
                    break;

                case QSLPlotCartesianSet::Triangles:
                    painter->drawLine( xi, yi-r, xi-r, yi+r);
                    painter->drawLine( xi-r, yi+r, xi+r, yi+r);
                    painter->drawLine( xi+r, yi+r, xi, yi-r);
                    break;

                case QSLPlotCartesianSet::FullTriangles:
                    polygon << QPoint(xi,yi-r)
                            << QPoint(xi-r,yi+r)
                            << QPoint(xi+r,yi+r);
                    painter->drawPolygon(polygon);
                    break;

                case QSLPlotCartesianSet::Squares:
                    painter->drawLine( xi-r, yi-r, xi-r, yi+r);
                    painter->drawLine( xi-r, yi+r, xi+r, yi+r);
                    painter->drawLine( xi+r, yi+r, xi+r, yi-r);
                    painter->drawLine( xi+r, yi-r, xi-r, yi-r);
                    break;

                case QSLPlotCartesianSet::FullSquares:
                    polygon << QPoint(xi-r,yi-r)
                            << QPoint(xi-r,yi+r)
                            << QPoint(xi+r,yi+r)
                            << QPoint(xi+r,yi-r);
                    painter->drawPolygon(polygon);
                    break;

                case QSLPlotCartesianSet::Plusses:
                    painter->drawLine(xi, yi-r, xi, yi+r);
                    painter->drawLine(xi-r, yi, xi+r, yi);
                    break;
            }
        }
        painter->drawText( xi -textWidth -8*r, yi +1.5*r, text);
    }
    painter->restore();
}


//QSLPlotLegend.cpp
