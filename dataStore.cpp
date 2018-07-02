#include "dataStore.h"
#include <QDebug>

DataStore::DataStore(QObject *parent)
    :QObject(parent)
    ,colorNum(0)
{

}

DataStore::~DataStore()
{

}

void DataStore::dealcolor()
{
//   colorNum = 1;//float(value/255);
    qDebug()<<"are you ok?";
}
