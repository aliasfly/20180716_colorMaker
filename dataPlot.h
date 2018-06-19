#ifndef DATAPLOT_H
#define DATAPLOT_H

#include <QObject>
#include <QAbstractSeries>
#include <QAbstractAxis>
#include <QScatterSeries>
#include <QXYSeries>
#include <QChart>
#include <QMap>

QT_CHARTS_USE_NAMESPACE


class DataPlot: public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QAbstractAxis* axisX READ axisX WRITE setAxisX)
//    Q_PROPERTY(QAbstractAxis* axisY READ axisY WRITE setAxisY)
public:
    DataPlot(QObject *parent = nullptr);
    ~DataPlot();

//    QAbstractAxis* axisX() const { return _axisX; }
//    QAbstractAxis* axisY() const { return _axisY; }


//    void setAxisX(QAbstractAxis* axisX);
//    void setAxisY(QAbstractAxis* axisY);


//public slots:
//    void seriesAdded(QAbstractSeries* series);
//    void seriesRemoved(QAbstractSeries* series);

private:
    QAbstractAxis*   _axisX;
    QAbstractAxis*   _axisY;
    QMap<QString, QAbstractSeries*> _nameToSeriesMap;

};
#endif   //DATAPLOT_H
