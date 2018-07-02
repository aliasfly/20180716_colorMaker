#ifndef DATAPLOT_H
#define DATAPLOT_H
#include <QObject>


class DataPlot  : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int xvalue READ xvalue WRITE setXvalue NOTIFY xvalueChanged)
    Q_PROPERTY(int yvalue READ yvalue WRITE setYvalue NOTIFY yvalueChanged)
public:
    DataPlot(QObject *parent = 0);
    ~DataPlot();

    int xvalue() const;
    void setXvalue(const int &xvalue);

    int yvalue() const;
    void setYvalue(const int &yvalue);

    double minValue() const { return _minValue; }           //to solve _minValue in #include "dataPlot.h" file
    double maxValue() const { return _maxValue; }           //to solve _maxValue in #include "dataPlot.h" file

signals:
    void xvalueChanged(const int &xvalue);
    void yvalueChanged(const int &yvalue);

public slots:
    void produceXYvalue();

private:
    int _xvalue;
    int _yvalue;
    double _minValue;
    double _maxValue;

};

#endif   //DATAPLOT_H
