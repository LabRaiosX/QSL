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


#ifndef QSLPLOTCARTESIAN_H
#define QSLPLOTCARTESIAN_H

#include "QSLPlotArea.h"
#include "QSLPlotCartesianSet.h"
#include "QSLPlotScale.h"
#include "QSLPlotLegend.h"


class QSL_LIB_DECL QSLPlotCartesian : public QSLPlotArea
{
    Q_OBJECT
public:
    explicit QSLPlotCartesian(QWidget *parent=0);
    QSLPlotCartesian(const QList<QSLPlotCartesianSet*> &plts, QWidget *parent=0);
    virtual ~QSLPlotCartesian();

    virtual QSLPlotCartesianSet* graph(int i)
    { return static_cast<QSLPlotCartesianSet*> (mPlots[i]); }

    virtual QSLPlotScale* axis(QSLPlotScale::ScalePosition pos);
    virtual QSLPlotLegend* legend() { return mLegend; }

public slots:
    virtual void setPlotables(const QList<QSLPlotCartesianSet*> &plts);
    virtual void addScale(QSLPlotScale *sca);
    virtual void exportPNG(const QString &fileName);
    virtual void setScalesColor(const QColor &col);
    
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

    QList<QSLPlotScale *> mScales;
    QSLPlotLegend *mLegend;

    QPoint mDragStartPoint;
    QPoint mDragEndPoint;
    bool mOnDrag;

private:
    Q_DISABLE_COPY(QSLPlotCartesian)
};

#endif // QSLPLOTCARTESIAN_H
