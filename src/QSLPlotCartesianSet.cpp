
#include "QSLPlotArea.h"
#include <QPainter>
#include <QPolygon>
#include "QSLPlotCartesianSet.h"
#include <QSLMath.h>


QSLPlotCartesianSet::QSLPlotCartesianSet(QObject *parent)
    : QSLPlotable(parent)
    , mDrawLine(false)
    , mDrawPoints(true)
    , mPointStyle(FullCircles)
    , mPointRadius(3)
{
    mHasThumbLegend = true;
}


QSLPlotCartesianSet::QSLPlotCartesianSet(const QSLArray1D<double> &xArr,
                                         const QSLArray1D<double> &yArr,
                                         QObject *parent)
    : QSLPlotable(parent)
    , mDrawLine(false)
    , mDrawPoints(true)
    , mPointStyle(FullCircles)
    , mPointRadius(3)
{
    mHasThumbLegend = true;
    setData(xArr,yArr);
}


QSLPlotCartesianSet::QSLPlotCartesianSet(const QVector<double> &xArr,
                                         const QVector<double> &yArr,
                                         QObject *parent)
    : QSLPlotable(parent)
    , mDrawLine(false)
    , mDrawPoints(true)
    , mPointStyle(FullCircles)
    , mPointRadius(3)
{
    mHasThumbLegend = true;
    setData(xArr,yArr);
}


QSLPlotCartesianSet::~QSLPlotCartesianSet() {}


void QSLPlotCartesianSet::setData(const QSLArray1D<double> &xArr,
                                  const QSLArray1D<double> &yArr)
{
    mX.setView(xArr);
    mY.setView(yArr);
    updateDataBounds();
    emit dataChanged();
}


void QSLPlotCartesianSet::setData(const QVector<double> &xArr,
                                  const QVector<double> &yArr)
{
    mX.setView(xArr);
    mY.setView(yArr);
    updateDataBounds();
    emit dataChanged();
}


void QSLPlotCartesianSet::updateData(const QSLArray1D<double> &xArr,
                                     const QSLArray1D<double> &yArr)
{
    setData(xArr,yArr);
}

void QSLPlotCartesianSet::updateDataNoRangeCheck(const QSLArray1D<double> &xArr,
                                                 const QSLArray1D<double> &yArr)
{
    mX.setView(xArr);
    mY.setView(yArr);
    emit dataChanged();
}


void QSLPlotCartesianSet::updateData(const QVector<double> &xArr,
                                     const QVector<double> &yArr)
{
    setData(xArr,yArr);
}


void QSLPlotCartesianSet::updateDataNoRangeCheck(const QVector<double> &xArr,
                                                 const QVector<double> &yArr)
{
    mX.setView(xArr);
    mY.setView(yArr);
    emit dataChanged();
}


void QSLPlotCartesianSet::clearData()
{
    mX.free();
    mY.free();
    setVisible(false);
}


void QSLPlotCartesianSet::copyData(const QSLArray1D<double> &xArr,
                                   const QSLArray1D<double> &yArr)
{
    mX.setCopy(xArr);
    mY.setCopy(yArr);
    updateDataBounds();
    emit dataChanged();
}


void QSLPlotCartesianSet::copyData(const QVector<double> &xArr,
                                   const QVector<double> &yArr)
{
    mX.setCopy(xArr);
    mY.setCopy(yArr);
    updateDataBounds();
    emit dataChanged();
}


void QSLPlotCartesianSet::updateDataBounds()
{
    mXmin = mXmax = mX[0];
    mYmin = mYmax = mY[0];
    for (int i=0; i<mX.size(); i++) {
        if (mX[i] < mXmin) mXmin=mX[i];
        if (mX[i] > mXmax) mXmax=mX[i];
        if (mY[i] < mYmin) mYmin=mY[i];
        if (mY[i] > mYmax) mYmax=mY[i];
    }
    emit rangesChanged();
}


void QSLPlotCartesianSet::setPointStyle(PointStyle sty)
{
    if (mPointStyle != sty) {
        mPointStyle = sty;
        emit appearenceChanged();
    }
}

void QSLPlotCartesianSet::setDrawLine(bool enabled)
{
    if (mDrawLine != enabled) {
        mDrawLine = enabled;
        emit appearenceChanged();
    }
}


void QSLPlotCartesianSet::setDrawPoints(bool enabled)
{
    if (mDrawPoints != enabled) {
        mDrawPoints = enabled;
        emit appearenceChanged();
    }
}


void QSLPlotCartesianSet::setPointRadius(int rad)
{
    if (mPointRadius != rad) {
        mPointRadius = rad;
        emit appearenceChanged();
    }
}


void QSLPlotCartesianSet::draw(QPainter *painter)
{
    if (!mVisible) return;

    painter->save();
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->setRenderHint(QPainter::Antialiasing, this->antialiased());

    if (mDrawPoints) {
        switch (mPointStyle) {
            case Circles:
                drawWithCircles(painter);
                break;

            case FullCircles:
                drawWithFullCircles(painter);
                break;

            case Triangles:
                drawWithTriangles(painter);
                break;

            case FullTriangles:
                drawWithFullTriangles(painter);
                break;

            case Squares:
                drawWithSquares(painter);
                break;

            case FullSquares:
                drawWithFullSquares(painter);
                break;

            case Plusses:
                drawWithPlusses(painter);
                break;
        }
    }

    if (mDrawLine) {
        drawWithLine(painter);
    }

    painter->restore();
}

#define BET(a,b,c) QSL::Math::between(a,b,c)

void QSLPlotCartesianSet::drawWithLine(QPainter *painter)
{
    double xmin = mParentPlot->xMin();
    double xmax = mParentPlot->xMax();
    double ymin = mParentPlot->yMin();
    double ymax = mParentPlot->yMax();
    for (int i=1; i<mX.size(); i++) {
        if ( BET(xmin, mX[i], xmax) && BET(ymin, mY[i], ymax)
             && BET(xmin, mX[i-1], xmax) && BET(ymin, mY[i-1], ymax) )
        {
            painter->drawLine( mParentPlot->xToPix(mX[i-1]),
                               mParentPlot->yToPix(mY[i-1]),
                               mParentPlot->xToPix(mX[i]), mParentPlot->yToPix(mY[i]));
        }
    }
}


void QSLPlotCartesianSet::drawWithCircles(QPainter *painter)
{
    painter->setBrush(Qt::NoBrush);
    int r = mPointRadius;
    for (int i=0; i<mX.size(); i++) {
        double x = mX[i];
        double y = mY[i];

        if (BET(mParentPlot->xMin(), x, mParentPlot->xMax())
            && BET(mParentPlot->yMin(), y, mParentPlot->yMax()))
        {
            painter->drawEllipse( mParentPlot->xToPix(x) -r,
                                  mParentPlot->yToPix(y) -r,
                                  2*r, 2*r );
        }
    }
}



void QSLPlotCartesianSet::drawWithFullCircles(QPainter *painter)
{
    int r = mPointRadius;
    for (int i=0; i<mX.size(); i++) {
        double x = mX[i];
        double y = mY[i];

        if (BET(mParentPlot->xMin(), x, mParentPlot->xMax())
            && BET(mParentPlot->yMin(), y, mParentPlot->yMax()))
        {
            painter->drawEllipse( mParentPlot->xToPix(x) -r,
                                  mParentPlot->yToPix(y) -r,
                                  2*r, 2*r );
        }
    }
}


void QSLPlotCartesianSet::drawWithTriangles(QPainter *painter)
{
    painter->setBrush(Qt::NoBrush);
    int r = mPointRadius;
    for (int i=0; i<mX.size(); i++) {
        double x = mX[i];
        double y = mY[i];

        if (BET(mParentPlot->xMin(), x, mParentPlot->xMax())
            && BET(mParentPlot->yMin(), y, mParentPlot->yMax()))
        {
            int xi = mParentPlot->xToPix(x);
            int yi = mParentPlot->yToPix(y);
            painter->drawLine( xi, yi-r, xi-r, yi+r);
            painter->drawLine( xi-r, yi+r, xi+r, yi+r);
            painter->drawLine( xi+r, yi+r, xi, yi-r);
        }
    }
}


void QSLPlotCartesianSet::drawWithFullTriangles(QPainter *painter)
{
    int r = mPointRadius;
    for (int i=0; i<mX.size(); i++) {
        double x = mX[i];
        double y = mY[i];

        if (BET(mParentPlot->xMin(), x, mParentPlot->xMax())
            && BET(mParentPlot->yMin(), y, mParentPlot->yMax()))
        {
            int xi = mParentPlot->xToPix(x);
            int yi = mParentPlot->yToPix(y);
            QPolygon polygon;
            polygon << QPoint(xi,yi-r)
                    << QPoint(xi-r,yi+r)
                    << QPoint(xi+r,yi+r);
            painter->drawPolygon(polygon);
        }
    }
}


void QSLPlotCartesianSet::drawWithSquares(QPainter *painter)
{
    painter->setBrush(Qt::NoBrush);
    int r = mPointRadius;
    for (int i=0; i<mX.size(); i++) {
        double x = mX[i];
        double y = mY[i];

        if (BET(mParentPlot->xMin(), x, mParentPlot->xMax())
            && BET(mParentPlot->yMin(), y, mParentPlot->yMax()))
        {
            int xi = mParentPlot->xToPix(x);
            int yi = mParentPlot->yToPix(y);
            painter->drawLine( xi-r, yi-r, xi-r, yi+r);
            painter->drawLine( xi-r, yi+r, xi+r, yi+r);
            painter->drawLine( xi+r, yi+r, xi+r, yi-r);
            painter->drawLine( xi+r, yi-r, xi-r, yi-r);
        }
    }
}


void QSLPlotCartesianSet::drawWithFullSquares(QPainter *painter)
{
    int r = mPointRadius;
    for (int i=0; i<mX.size(); i++) {
        double x = mX[i];
        double y = mY[i];

        if (BET(mParentPlot->xMin(), x, mParentPlot->xMax())
            && BET(mParentPlot->yMin(), y, mParentPlot->yMax()))
        {
            int xi = mParentPlot->xToPix(x);
            int yi = mParentPlot->yToPix(y);
            QPolygon polygon;
            polygon << QPoint(xi-r,yi-r)
                    << QPoint(xi-r,yi+r)
                    << QPoint(xi+r,yi+r)
                    << QPoint(xi+r,yi-r);
            painter->drawPolygon(polygon);
        }
    }
}


void QSLPlotCartesianSet::drawWithPlusses(QPainter *painter)
{
    int r = mPointRadius;
    for (int i=0; i<mX.size(); i++) {
        double x = mX[i];
        double y = mY[i];

        if (BET(mParentPlot->xMin(), x, mParentPlot->xMax())
            && BET(mParentPlot->yMin(), y, mParentPlot->yMax()))
        {
            int xi = mParentPlot->xToPix(x);
            int yi = mParentPlot->yToPix(y);
            painter->drawLine( xi-r, yi, xi+r, yi);
            painter->drawLine( xi, yi-r, xi, yi+r);
        }
    }
}

#undef BET

// QSLPlotCartesianSet.cpp
