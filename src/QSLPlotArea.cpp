
#include <QtGui>
#include "QSLPlotArea.h"
#include "QSLPlotable.h"


QSLPlotArea::QSLPlotArea(QWidget *parent)
    : QWidget(parent)
    , mXlowerBound(20)
    , mXupperBound(20)
    , mYlowerBound(20)
    , mYupperBound(20)
{
    setXrange(0,1);
    setYrange(0,1);
    setBackColor(Qt::white);
    setAutoFillBackground(true);
    setMinimumSize(600,400);
    QObject::connect(this, SIGNAL(appearenceChanged()), this, SLOT(repaint()));
    QObject::connect(this, SIGNAL(plotsChanged()), this, SLOT(replot()));
}


QSLPlotArea::QSLPlotArea(const QList<QSLPlotable *> &plts, QWidget *parent)
    : QWidget(parent)
    , mXlowerBound(20)
    , mXupperBound(20)
    , mYlowerBound(20)
    , mYupperBound(20)
{
    setBackColor(Qt::white);
    setAutoFillBackground(true);
    setMinimumSize(600,400);
    QObject::connect(this, SIGNAL(appearenceChanged()), this, SLOT(repaint()));
    QObject::connect(this, SIGNAL(plotsChanged()), this, SLOT(replot()));
    setPlotables(plts);
}


QSLPlotArea::~QSLPlotArea() {}


void QSLPlotArea::addPlotable(QSLPlotable *plt)
{
    if (mPlots.size() == 0) {
        mXminData = plt->xMin();
        mXmaxData = plt->xMax();
        mYminData = plt->yMin();
        mYmaxData = plt->yMax();
    } else {
        if (plt->xMin() < mXminData) mXminData = plt->xMin();
        if (plt->xMax() > mXmaxData) mXmaxData = plt->xMax();
        if (plt->yMin() < mYminData) mYminData = plt->yMin();
        if (plt->yMax() > mYmaxData) mYmaxData = plt->yMax();
    }

    QObject::connect(plt, SIGNAL(appearenceChanged()), this, SLOT(repaint()));
    QObject::connect(plt, SIGNAL(dataChanged()), this, SLOT(replot()));
    QObject::connect(plt, SIGNAL(rangesChanged()), this, SLOT(rescale()));

    plt->mParentPlot = this;
    mPlots.append(plt);

    setXrange(mXminData,mXmaxData);
    setYrange(mYminData,mYmaxData);

    emit plotsChanged();
}


void QSLPlotArea::setPlotables(const QList<QSLPlotable *> &plts)
{
    foreach(QSLPlotable *plt, plts) {
        addPlotable(plt);
    }
}


void QSLPlotArea::removePlotable(int i)
{
    mPlots[i]->mParentPlot = 0;
    mPlots.removeAt(i);
    mXminData = mPlots[0]->xMin();
    mXmaxData = mPlots[0]->xMax();
    mYminData = mPlots[0]->yMin();
    mYmaxData = mPlots[0]->yMax();
    for (int i=1; i<mPlots.size(); i++) {
        QSLPlotable *plt = mPlots[i];
        if (plt->xMin() < mXminData) mXminData = plt->xMin();
        if (plt->xMax() > mXmaxData) mXmaxData = plt->xMax();
        if (plt->yMin() < mYminData) mYminData = plt->yMin();
        if (plt->yMax() > mYmaxData) mYmaxData = plt->yMax();
    }
    emit plotsChanged();
}


void QSLPlotArea::removeAllPlotables()
{
    foreach(QSLPlotable* plt, mPlots) {
        plt->mParentPlot = 0;
    }
    mPlots.clear();
    emit plotsChanged();
}


int QSLPlotArea::xToPix(double x)
{
    double tmp = (x-mXmin)/(mXmax-mXmin);
    tmp *= (mXmaxPix-mXminPix);
    return mXminPix + int(tmp);
}


int QSLPlotArea::yToPix(double y)
{
    double tmp = (y-mYmin)/(mYmax-mYmin);
    tmp *= (mYmaxPix-mYminPix);
    return mHeight - mYminPix - int(tmp);
}


double QSLPlotArea::pixToX(int xp)
{
    double tmp = xp - mXminPix;
    tmp /= (mXmaxPix-mXminPix);
    tmp *= (mXmax-mXmin);
    return mXmin + tmp;
}


double QSLPlotArea::pixToY(int yp)
{
    double tmp = mHeight - mYminPix - yp;
    tmp /= (mYmaxPix-mYminPix);
    tmp *= (mYmax-mYmin);
    return mYmin + tmp;
}


void QSLPlotArea::setXrange(double xi, double xf)
{
    mXmin = xi;
    mXmax = xf;
    emit regionChanged();
}


void QSLPlotArea::setYrange(double yi, double yf)
{
    mYmin = yi;
    mYmax = yf;
    emit regionChanged();
}


void QSLPlotArea::setGraphXbounds(int xi, int xf)
{
    mXlowerBound = xi;
    mXupperBound = xf;
    emit appearenceChanged();
}


void QSLPlotArea::setGraphYbounds(int yi, int yf)
{
    mYlowerBound = yi;
    mYupperBound = yf;
    emit appearenceChanged();
}


void QSLPlotArea::setBackColor(const QColor &col)
{
    QPalette palette = this->palette();
    palette.setColor(backgroundRole(), col);
    this->setPalette(palette);
    emit appearenceChanged();
}


void QSLPlotArea::replot()
{
    repaint();
}


void QSLPlotArea::rescale()
{
    mXminData = mPlots[0]->xMin();
    mXmaxData = mPlots[0]->xMax();
    mYminData = mPlots[0]->yMin();
    mYmaxData = mPlots[0]->yMax();
    for (int i=1; i<mPlots.size(); i++) {
        QSLPlotable *plt = mPlots.at(i);
        if (plt->xMin() < mXminData) mXminData = plt->xMin();
        if (plt->xMax() > mXmaxData) mXmaxData = plt->xMax();
        if (plt->yMin() < mYminData) mYminData = plt->yMin();
        if (plt->yMax() > mYmaxData) mYmaxData = plt->yMax();
    }
    setXrange(mXminData,mXmaxData);
    setYrange(mYminData,mYmaxData);
    emit appearenceChanged();
}


void QSLPlotArea::rescale(QSLPlotable *plt)
{
    setXrange(plt->xMin(),plt->xMax());
    setYrange(plt->yMin(),plt->yMax());
    emit appearenceChanged();
}


void QSLPlotArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    updateBounds();
    QPainter *painter = new QPainter(this);
    for (int i=0; i<mPlots.size(); i++) {
        plot(i)->draw(painter);
    }
    delete painter;
}


void QSLPlotArea::updateBounds()
{
    mWidth = width();
    mXminPix = mXlowerBound;
    mXmaxPix = mWidth - mXupperBound;
    mHeight = height();
    mYminPix = mYlowerBound;
    mYmaxPix = mHeight - mYupperBound;
}


//QSLPlotArea.cpp
