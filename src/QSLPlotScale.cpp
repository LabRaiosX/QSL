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

#include "QSLPlotScale.h"
#include <QPainter>
#include <QTextStream>
#include <QSLPlotArea.h>

QSLPlotScale::QSLPlotScale(ScalePosition pos, QObject *parent)
    : QSLPlotable(parent)
    , mPosit(pos)
{
    switch (pos) {
    case Bottom:
        mTitle = "X Axis";
        break;
    case Left:
        mTitle = "Y Axis";
        break;
    case Top:
        mTitle = "X Axis 2";
        break;
    case Right:
        mTitle = "Y Axis 2";
        break;
    }
}


QSLPlotScale::~QSLPlotScale() {}

void QSLPlotScale::setPosition(ScalePosition pos)
{
    if (mPosit != pos) {
        mPosit = pos;
        emit appearenceChanged();
    }
}


void QSLPlotScale::update(double minData, double maxData, int minPix, int maxPix, int perpDist)
{
    int divLen = 80;
    switch (mPosit) {
    case Bottom:
        divLen = 80;
        break;
    case Left:
        divLen = 50;
        break;
    case Top:
        divLen = 80;
        break;
    case Right:
        divLen = 50;
        break;
    }

    mMinPix = minPix;
    mMaxPix = maxPix;
    mMinData = minData;
    mMaxData = maxData;
    mPerpDist = perpDist;
    mDivLenPix = divLen;
    mDivNum = (maxPix - minPix)/mDivLenPix;
    mDivLenPix += ((maxPix - minPix)%divLen)/mDivNum;
    mDivLenData = (maxData - minData)/mDivNum;
}


void QSLPlotScale::draw(QPainter *painter, QFontMetrics *fontMetrics)
{
    painter->save();
    painter->setPen(this->pen());
    painter->setBrush(this->brush());

    int textHeight = fontMetrics->height();
    QString buf;
    QTextStream str(&buf);
    str.setRealNumberNotation(QTextStream::SmartNotation);
    str.setRealNumberPrecision(3);
    int plotHeight = mParentPlot->height();
    int plotWidth = mParentPlot->width();

    switch (mPosit) {
    case Bottom:
        painter->drawLine(mMinPix, plotHeight-mPerpDist,
                          mMaxPix, plotHeight-mPerpDist);
        for (int i=0; i<mDivNum; i++) {
            double val = mParentPlot->pixToX(mMinPix + i*mDivLenPix);
            str << val;
            int textWidth = fontMetrics->width(buf);
            int x = mMinPix + i*mDivLenPix;
            int y = plotHeight - mPerpDist;
            painter->drawText(x - textWidth/2, y + 1.2*textHeight, buf);
            painter->drawLine(x,y,x,y-7);
            buf.clear();
        }
        break;

    case Left:
        painter->drawLine(mPerpDist, plotHeight-mMinPix, mPerpDist, plotHeight-mMaxPix);
        for (int i=1; i<=mDivNum; i++) {
            double val = mParentPlot->pixToY(plotHeight - mMinPix - i*mDivLenPix);
            str << val;
            int textWidth = fontMetrics->width(buf);
            int x = mPerpDist;
            int y = plotHeight - mMinPix - i*mDivLenPix;
            painter->drawText(x-textWidth - 0.5*textHeight, y + 0.5*textHeight, buf);
            painter->drawLine(x,y,x+7,y);
            buf.clear();
        }
        break;

    case Top:
        painter->drawLine(mMinPix, mPerpDist, mMaxPix, mPerpDist);
        for (int i=1; i<=mDivNum; i++) {
            double val = mParentPlot->pixToX(mMinPix + i*mDivLenPix);
            str << val;
            int textWidth = fontMetrics->width(buf);
            int x = mMinPix + i*mDivLenPix;
            int y = mPerpDist;
            painter->drawText(x - textWidth/2, y - 0.5*textHeight, buf);
            painter->drawLine(x,y,x,y+7);
            buf.clear();
        }
        break;

    case Right:
        painter->drawLine(plotWidth-mPerpDist, plotHeight-mMinPix, plotWidth-mPerpDist, plotHeight-mMaxPix);
        for (int i=0; i<mDivNum; i++) {
            double val = mParentPlot->pixToY(plotHeight - mMinPix - i*mDivLenPix);
            str << val;
            int x = plotWidth-mPerpDist;
            int y = plotHeight - mMinPix - i*mDivLenPix;
            painter->drawText(x+5, y + 0.5*textHeight, buf);
            painter->drawLine(x,y,x-7,y);
            buf.clear();
        }
        break;
    }

    painter->restore();
}


void QSLPlotScale::drawLegend(QPainter *painter, QFontMetrics *fontMetrics)
{
    painter->save();
    painter->setPen(this->pen());
    painter->setBrush(this->brush());

    int plotHeight = mParentPlot->height();
    int plotWidth = mParentPlot->width();
    int textWidth = fontMetrics->width(mTitle);
    int textHeight = fontMetrics->height();
    switch (mPosit) {
    case Bottom:
        painter->drawText( (mMinPix+mMaxPix -textWidth)/2,
                           plotHeight -mPerpDist +2.5*textHeight,
                           mTitle );
        break;

    case Left:
        painter->rotate(-90.0);
        painter->drawText(-plotHeight +(mMinPix+mMaxPix)/2 -0.5*textWidth,
                          1.5*textHeight,
                          mTitle );
        break;

    case Top:
        painter->drawText( (mMinPix+mMaxPix -textWidth)/2,
                           mPerpDist - 2.0*textHeight,
                           mTitle );
        break;

    case Right:
        painter->rotate(-90.0);
        painter->drawText(-plotHeight +(mMinPix+mMaxPix)/2 -0.5*textWidth,
                          plotWidth -1.0*textHeight,
                          mTitle );
    }

    painter->restore();
}


//QSLPlotScale.cpp
