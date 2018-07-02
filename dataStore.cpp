#include "dataStore.h"
#include <QDebug>
#include "stdlib.h"
#include "math.h"

DataStore::DataStore(QObject *parent)
    :QObject(parent)
    ,_colorNumR(0)
    ,_colorNumG(0)
    ,_colorNumB(0)
    ,_randColorNumR(0)
    ,_randColorNumG(0)
    ,_randColorNumB(0)
{

}

DataStore::~DataStore()
{

}
void DataStore::produceRand()
{
    float max,sum;
    do
    {
        _randColorNumR=float(rand()%100)/100;
        _randColorNumG=float(rand()%100)/100;
        _randColorNumB=float(rand()%100)/100;
         qDebug()<<"_randColorNumR="<<_randColorNumR;
         qDebug()<<"_randColorNumG="<<_randColorNumG;
         qDebug()<<"_randColorNumB="<<_randColorNumB;
        max=_randColorNumR;
        if(max<_randColorNumG)
        {
            max=_randColorNumG;
        }
        else
        {
            if(max<_randColorNumB)
            {
               max=_randColorNumB;
            }
        }
        if(max<_randColorNumB)
        {
            max=_randColorNumB;
        }

        sum=_randColorNumR+_randColorNumG+_randColorNumB;
        qDebug()<<"max="<<max;
        qDebug()<<"sum="<<sum;

    }while(max<0.5 || sum>2);
}

void DataStore::calculateSquareError()
{
    float rFabs,gFabs,bFabs;
    rFabs=fabs(_colorNumR-_randColorNumR)*fabs(_colorNumR-_randColorNumR);
    gFabs=fabs(_colorNumG-_randColorNumG)*fabs(_colorNumG-_randColorNumG);
    bFabs=fabs(_colorNumB-_randColorNumB)*fabs(_colorNumB-_randColorNumB);
    _squareError=int(sqrt(rFabs+gFabs+bFabs)*100);

    qDebug()<<"_squareError="<<_squareError;
}

void DataStore::dealcolorR(int value)
{
//   float temp=float(value);
   _colorNumR = float(value)/255;
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
