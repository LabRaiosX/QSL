
#ifndef QSL_PLOTABLE_H
#define QSL_PLOTABLE_H

#include <QObject>
#include <QString>
#include <QPen>
#include <QColor>
#include <QBrush>
#include "QSLGlobal.h"

class QSLPlotArea;
class QPainter;

class QSL_LIB_DECL QSLPlotable : public QObject
{
    Q_OBJECT
public:
    explicit QSLPlotable(QObject *parent=0);
    virtual ~QSLPlotable();
    
    //getters
    QString title() const { return mTitle; }
    QPen pen() const { return mPen; }
    QBrush brush() const { return mBrush; }
    bool visible() const { return mVisible; }
    bool antialiased() const { return mAntialiased; }
    bool hasThumbLegend() const { return mHasThumbLegend; }
    double xMin() const { return mXmin; }
    double xMax() const { return mXmax; }
    double yMin() const { return mYmin; }
    double yMax() const { return mYmax; }
    QSLPlotArea* parentPlot() { return mParentPlot; }
    
public slots:
    //setters
    void setTitle(const QString &tit);
    void setPen(const QPen &pn);
    void setBrush(const QBrush &br);
    void setColor(const QColor &col);
    void setVisible(bool on);
    void setAntialiased(bool on);
    
signals:
    void appearenceChanged();
    void dataChanged();
    void rangesChanged();
    
protected:
    virtual void draw(QPainter *painter);
    
    QSLPlotArea *mParentPlot;
    
    double mXmin, mXmax;
    double mYmin, mYmax;
    
    QString mTitle;
    QPen mPen;
    QBrush mBrush;
    bool mVisible;
    bool mAntialiased;
    bool mHasThumbLegend;
    
private:
    friend class QSLPlotArea;
    Q_DISABLE_COPY(QSLPlotable)
};

#endif //QSL_PLOTABLE_H
