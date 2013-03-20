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


#ifndef QSL_PLOTSCALE_H
#define QSL_PLOTSCALE_H

#include "QSLPlotable.h"

class QSLPlotCartesian;


class QSL_LIB_DECL QSLPlotScale : public QSLPlotable
{
    Q_OBJECT
public:

    enum ScalePosition
    {
        Left,
        Right,
        Bottom,
        Top
    };

    QSLPlotScale(ScalePosition pos, QObject *parent = 0);
    virtual ~QSLPlotScale();

    ScalePosition position() const { return mPosit; }
    
signals:
    
public slots:
    void setPosition(ScalePosition pos);

protected slots:
    void update(double minData, double maxData, int minPix, int maxPix, int perpDist);

protected:
    virtual void draw(QPainter *painter, QFontMetrics *fontMetrics);
    virtual void drawLegend(QPainter *painter, QFontMetrics *fontMetrics);

    ScalePosition mPosit;
    int mDivNum;
    int mDivLenPix;
    int mDivLenData;

    double mMinData;
    double mMaxData;
    int mMinPix;
    int mMaxPix;

    int mPerpDist;

private:
    friend class QSLPlotCartesian;
    Q_DISABLE_COPY(QSLPlotScale)
};

#endif // QSL_PLOTSCALE_H
