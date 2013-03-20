 
#include "QSLPlotable.h"
#include <QPainter>

QSLPlotable::QSLPlotable(QObject *parent)
    : QObject(parent)
    , mTitle("New Plot")
    , mPen(QPen(Qt::black))
    , mBrush(QBrush(Qt::black,Qt::SolidPattern))
    , mVisible(true)
    , mAntialiased(false)
    , mHasThumbLegend(false)
{}


QSLPlotable::~QSLPlotable() {}


void QSLPlotable::setTitle(const QString &tit)
{
    if (mTitle!=tit) {
        mTitle = tit;
        emit appearenceChanged();
    }
}


void QSLPlotable::setPen(const QPen &pen)
{
    mPen = pen;
    emit appearenceChanged();
}


void QSLPlotable::setBrush(const QBrush &br)
{
    mBrush = br;
    emit appearenceChanged();
}


void QSLPlotable::setVisible(bool on)
{
    if (mVisible!=on) {
        mVisible = on;
        emit appearenceChanged();
    }
}


void QSLPlotable::setAntialiased(bool on)
{
    if (mAntialiased!=on) {
        mAntialiased = on;
        emit appearenceChanged();
    }
}


void QSLPlotable::setColor(const QColor &col)
{
    mPen.setColor(col);
    mBrush = QBrush(col);
    emit appearenceChanged();
}


void QSLPlotable::draw(QPainter *painter)
{
    Q_UNUSED(painter)
}


//QSLPlotable.cpp
