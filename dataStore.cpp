#include "dataStore.h"
#include <QDebug>

DataStore::DataStore(QObject *parent)
    :QObject(parent)
    ,_colorNumR(0)
    ,_colorNumG(0)
    ,_colorNumB(0)
{

}

DataStore::~DataStore()
{

}

void DataStore::dealcolorR(int value)
{
   float temp=float(value);
   _colorNumR = float(temp/255);
   qDebug()<<"value="<<value;
   qDebug()<<"are you ok?";
   qDebug()<<"colorNumR="<<_colorNumR;
}
void DataStore::dealcolorG(int value)
{
   float temp=float(value);
   _colorNumG = float(temp/255);
   qDebug()<<"colorNumG="<<_colorNumG;
}
void DataStore::dealcolorB(int value)
{
   float temp=float(value);
   _colorNumB = float(temp/255);
   qDebug()<<"colorNumB="<<_colorNumB;
}
