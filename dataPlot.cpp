#include "dataPlot.h"


DataPlot::DataPlot(QObject *parent): QObject(parent)
{

}

DataPlot::~DataPlot()
{
    _nameToSeriesMap.clear();
    _axisX = _axisY = NULL;
}
