
#ifndef QSL_PLOTCERTESIANSET_H
#define QSL_PLOTCERTESIANSET_H

#include "QSLGlobal.h"
#include "QSLPlotable.h"
#include "QSLArray1D.h"

class QSLPlotArea;

QT_BEGIN_NAMESPACE
template<typename T> class QVector;
QT_END_NAMESPACE


class QSL_LIB_DECL QSLPlotCartesianSet : public QSLPlotable
{
    Q_OBJECT
public:
    
    enum PointStyle
    {
        Circles,
        FullCircles,
        Triangles,
        FullTriangles,
        Squares,
        FullSquares,
        Plusses
    };
    
    explicit QSLPlotCartesianSet(QObject *parent=0);
    QSLPlotCartesianSet(const QSLArray1D<double> &xArr, const QSLArray1D<double> &yArr, QObject *parent=0);
    QSLPlotCartesianSet(const QVector<double> &xArr, const QVector<double> &yArr, QObject *parent=0);
    virtual ~QSLPlotCartesianSet();
    
    //getters
    int numPts() const { return mX.size(); }
    PointStyle pointStyle() const { return mPointStyle; }
    bool drawLine() const { return mDrawLine; }
    bool drawPoints() const { return mDrawPoints; }
    int pointRadius() const { return mPointRadius; }
    QSLArray1D<double>& dataX() { return mX; }
    QSLArray1D<double>& dataY() { return mY; }
    
    
    virtual void setData(const QSLArray1D<double> &xArr, const QSLArray1D<double> &yArr);
    virtual void updateData(const QSLArray1D<double> &xArr, const QSLArray1D<double> &yArr);
    virtual void updateDataNoRangeCheck(const QSLArray1D<double> &xArr, const QSLArray1D<double> &yArr);
    virtual void setData(const QVector<double> &xArr, const QVector<double> &yArr);
    virtual void updateData(const QVector<double> &xArr, const QVector<double> &yArr);
    virtual void updateDataNoRangeCheck(const QVector<double> &xArr, const QVector<double> &yArr);
    virtual void copyData(const QSLArray1D<double> &xArr, const QSLArray1D<double> &yArr);
    virtual void copyData(const QVector<double> &xArr, const QVector<double> &yArr);
    virtual void clearData();
    
signals:

public slots:
    //setters
    void setPointStyle(PointStyle sty);
    void setDrawLine(bool enabled);
    void setDrawPoints(bool enabled);
    void setPointRadius(int rad);
    
protected:
    void updateDataBounds();

    virtual void draw(QPainter *painter);
    void drawWithLine(QPainter *painter);
    void drawWithCircles(QPainter *painter);
    void drawWithFullCircles(QPainter *painter);
    void drawWithTriangles(QPainter *painter);
    void drawWithFullTriangles(QPainter *painter);
    void drawWithSquares(QPainter *painter);
    void drawWithFullSquares(QPainter *painter);
    void drawWithPlusses(QPainter *painter);
    
    bool mDrawLine;
    bool mDrawPoints;
    PointStyle mPointStyle;
    QSLArray1D<double> mX, mY;
    int mPointRadius;
    
private:
    friend class QSLPlotArea;
    Q_DISABLE_COPY(QSLPlotCartesianSet)
};


#endif //QSL_PLOTCERTESIANSET_H
