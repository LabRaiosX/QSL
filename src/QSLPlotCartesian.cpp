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

#include "QSLPlotCartesian.h"
#include <QPainter>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>


QSLPlotCartesian::QSLPlotCartesian(QWidget *parent)
    : QSLPlotArea(parent)
    , mOnDrag(false)
{
    setGraphXbounds(100,100);
    setGraphYbounds(50,50);

    addScale(new QSLPlotScale(QSLPlotScale::Top));
    addScale(new QSLPlotScale(QSLPlotScale::Bottom));
    addScale(new QSLPlotScale(QSLPlotScale::Left));
    addScale(new QSLPlotScale(QSLPlotScale::Right));
    
    foreach (QSLPlotScale *sca, mScales) {
        QObject::connect(sca, SIGNAL(appearenceChanged()), this, SLOT(repaint()));
    }

    mLegend = new QSLPlotLegend(this);
}


QSLPlotCartesian::QSLPlotCartesian(const QList<QSLPlotCartesianSet*> &plts, QWidget *parent)
    : QSLPlotArea(parent)
    , mOnDrag(false)
{
    setGraphXbounds(100,100);
    setGraphYbounds(50,50);

    addScale(new QSLPlotScale(QSLPlotScale::Top));
    addScale(new QSLPlotScale(QSLPlotScale::Bottom));
    addScale(new QSLPlotScale(QSLPlotScale::Left));
    addScale(new QSLPlotScale(QSLPlotScale::Right));
    
    foreach (QSLPlotScale *sca, mScales) {
        QObject::connect(sca, SIGNAL(appearenceChanged()), this, SLOT(repaint()));
    }

    mLegend = new QSLPlotLegend(this);

    setPlotables(plts);
}


QSLPlotCartesian::~QSLPlotCartesian() {}


void QSLPlotCartesian::setPlotables(const QList<QSLPlotCartesianSet *> &plts)
{
    foreach(QSLPlotCartesianSet *plt, plts) {
        addPlotable(plt);
    }
}


void QSLPlotCartesian::addScale(QSLPlotScale *sca)
{
    sca->mParentPlot = this;
    mScales.append(sca);
}


QSLPlotScale* QSLPlotCartesian::axis(QSLPlotScale::ScalePosition pos)
{
    switch (pos) {
    case QSLPlotScale::Top:
        return mScales[0];
        break;
    case QSLPlotScale::Bottom:
        return mScales[1];
        break;
    case QSLPlotScale::Left:
        return mScales[2];
        break;
    case QSLPlotScale::Right:
        return mScales[3];
        break;
    }
    //only to avoid compile error "control reaches end of non-void function"
    return mScales[0];
}


void QSLPlotCartesian::paintEvent(QPaintEvent *event)
{
    QSLPlotArea::paintEvent(event);

    QPainter *painter = new QPainter(this);
    QFontMetrics fontMetrics = this->fontMetrics();

    foreach(QSLPlotScale *sca, mScales) {
        if (!sca->visible()) break;
        switch (sca->position()) {
            case QSLPlotScale::Bottom:
                sca->update(mXmin, mXmax, mXminPix, mXmaxPix, mYlowerBound);
                break;

            case QSLPlotScale::Left:
                sca->update(mYmin, mYmax, mYminPix, mYmaxPix, mXlowerBound);
                break;

            case QSLPlotScale::Top:
                sca->update(mXmin, mXmax, mXminPix, mXmaxPix, mYupperBound);
                break;

            case QSLPlotScale::Right:
                sca->update(mYmin, mYmax, mYminPix, mYmaxPix, mXupperBound);
                break;
        }
        sca->draw(painter, &fontMetrics);
        sca->drawLegend(painter, &fontMetrics);
    }

    mLegend->draw(painter, &fontMetrics, mPlots, mXmaxPix -14, mYupperBound +22);

    if (mOnDrag) {
        QPen mouseRectPen(mScales[0]->pen().color());
        mouseRectPen.setStyle(Qt::DashLine);
        painter->setPen(mouseRectPen);
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(mDragStartPoint.x(),mDragStartPoint.y(),
                          mDragEndPoint.x()-mDragStartPoint.x(),
                          mDragEndPoint.y()-mDragStartPoint.y());
    }

    delete painter;
}


void QSLPlotCartesian::exportPNG(const QString &fileName)
{
    QPixmap pixmap = QPixmap::grabWidget(this);
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly)) {
        QMessageBox::warning(this, "ERROR export PNG",
                             "QSLPlotCartesian: couldn't open PNG file for writing!",
                             0,0);
    }
    pixmap.save(fileName,"png");
}


void QSLPlotCartesian::setScalesColor(const QColor &col)
{
    foreach (QSLPlotScale *sca, mScales) {
        sca->setColor(col);
    }
}


void QSLPlotCartesian::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mOnDrag = true;
        mDragStartPoint = event->pos();
    }
    if (event->button() == Qt::RightButton) {
        rescale();
    }
}


void QSLPlotCartesian::mouseMoveEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mDragEndPoint = event->pos();
        repaint();
    }
}


void QSLPlotCartesian::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mOnDrag = false;
        mDragEndPoint = event->pos();
        if (mDragEndPoint.x()<mDragStartPoint.x()) {
            int tmp = mDragEndPoint.x();
            mDragEndPoint.setX(mDragStartPoint.x());
            mDragStartPoint.setX(tmp);
        }
        if (mDragEndPoint.y()<mDragStartPoint.y()) {
            int tmp = mDragEndPoint.y();
            mDragEndPoint.setY(mDragStartPoint.y());
            mDragStartPoint.setY(tmp);
        }
        setXrange(pixToX(mDragStartPoint.x()),pixToX(mDragEndPoint.x()));
        setYrange(pixToY(mDragEndPoint.y()),pixToY(mDragStartPoint.y()));
        repaint();
    }
}

//QSLPlotCartesian.cpp
