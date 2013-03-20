
#ifndef QSL_PLOTAREA_H
#define QSL_PLOTAREA_H

#include <QWidget>
#include "QSLGlobal.h"
#include "QSLPlotable.h"


class QSL_LIB_DECL QSLPlotArea : public QWidget
{
    Q_OBJECT
public:
    explicit QSLPlotArea(QWidget *parent=0);
    QSLPlotArea(const QList<QSLPlotable*> &plts, QWidget *parent=0);
    virtual ~QSLPlotArea();

    virtual void addPlotable(QSLPlotable *plt);
    virtual void setPlotables(const QList<QSLPlotable*> &plts);
    virtual void removePlotable(int i);
    virtual void removeAllPlotables();

    int xToPix(double x);
    int yToPix(double y);
    double pixToX(int xp);
    double pixToY(int yp);

    double xMax() const { return mXmax; }
    double xMin() const { return mXmin; }
    double yMax() const { return mYmax; }
    double yMin() const { return mYmin; }

    virtual QSLPlotable* plot(int i) { return mPlots[i]; }
    int numPlots() const { return mPlots.size(); }

public slots:
    void setXrange(double xi, double xf);
    void setYrange(double yi, double yf);
    void setGraphXbounds(int xi, int xf);
    void setGraphYbounds(int yi, int yf);
    void setBackColor(const QColor &col);
    virtual void replot();
    virtual void rescale();
    virtual void rescale(QSLPlotable *plt);

signals:
    void plotsChanged();
    void appearenceChanged();
    void regionChanged();

protected:
    virtual void paintEvent(QPaintEvent *event);
    void updateBounds();

    QList<QSLPlotable*> mPlots;

    double mXmin, mXmax;
    double mYmin, mYmax;
    double mXminData, mXmaxData;
    double mYminData, mYmaxData;

    int mXminPix, mXmaxPix;
    int mYminPix, mYmaxPix;
    int mXlowerBound, mXupperBound;
    int mYlowerBound, mYupperBound;
    int mHeight, mWidth;

    QColor mBackColor;

private:
    Q_DISABLE_COPY(QSLPlotArea)
};

#endif //QSL_PLOTAREA_H
