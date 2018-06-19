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

signals:
    void xvalueChanged(const int &xvalue);
    void yvalueChanged(const int &yvalue);

private:
    int _xvalue;
    int _yvalue;

};

#endif   //DATAPLOT_H
