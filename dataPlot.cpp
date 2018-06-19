#include "dataPlot.h"

DataPlot::DataPlot(QObject *parent)
    :QObject(parent)
    ,_xvalue(0)
    ,_yvalue(0)
{

}

DataPlot::~DataPlot()
{

}

int DataPlot::xvalue() const
{
    return _xvalue;
}
void DataPlot::setXvalue(const int &xvalue)
{
        _xvalue=xvalue;
        emit xvalueChanged(_xvalue);
}

int DataPlot::yvalue() const
{
    return _yvalue;
}
void DataPlot::setYvalue(const int &yvalue)
{
    _yvalue=yvalue;
    emit yvalueChanged(_yvalue);
}



void DataPlot::produceXYvalue()
{
    for(int i=0;i<10;i++)
    {
        DataPlot::setXvalue(i);
//        DataPlot::setYvalue(i);
    }
}
