#include "colorMaker.h"
#include <QFile>
#include <QDebug>
#include <QByteArray>

//#include <QTimerEvent>
//#include <QDateTime>

#include <iostream>
#include <stdlib.h>

ColorMaker::ColorMaker(QObject *parent)
    :QObject(parent)
{

}

ColorMaker::~ColorMaker()
{

}

void ColorMaker::ProduceRange()
{
    int a[10];
    for(int i=0;i<10;i++)
    {
       a[i]=rand()%20;
       qDebug()<<a[i]<<" ";
    }
}

void ColorMaker::ReadFile()
{
    qint64 pos;
    QFile file("///home/zx/Documents/QplotTest/testdata.txt");// _filePath
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug()<< file.fileName() << file.exists();
        qDebug()<<"file open failed!!!!!!!!!!!";
        return;
    }
    qDebug()<<"open file ok";
    qDebug()<< file.fileName() << file.exists();    
    pos = file.size();
    qDebug()<<"file.size="<<pos<<endl;
    while (!file.atEnd())
    {
        QByteArray dat = file.read(30);
        char *da=dat.data();
        while(*da)
        {
            qDebug()<<*da;
            da++;
        }
    }   
}







//ColorMaker::ColorMaker(QObject *parent)
//    : QObject(parent)
//    , m_algorithm(RandomRGB)
//    , m_currentColor(Qt::black)
//    , m_nColorTimer(0)
//{
//    qsrand(QDateTime::currentDateTime().toTime_t());
//}

//ColorMaker::~ColorMaker()
//{
//}

//QColor ColorMaker::color() const
//{
//    return m_currentColor;
//}

//void ColorMaker::setColor(const QColor &color)
//{
//    m_currentColor = color;
//    emit colorChanged(m_currentColor);
//}

//QColor ColorMaker::timeColor() const
//{
//    QTime time = QTime::currentTime();
//    int r = time.hour();
//    int g = time.minute()*2;
//    int b = time.second()*4;
//    return QColor::fromRgb(r, g, b);
//}

//ColorMaker::GenerateAlgorithm ColorMaker::algorithm() const
//{
//    return m_algorithm;
//}

//void ColorMaker::setAlgorithm(GenerateAlgorithm algorithm)
//{
//    m_algorithm = algorithm;
//}

//void ColorMaker::start()
//{
//    if(m_nColorTimer == 0)
//    {
//        m_nColorTimer = startTimer(1000);
//    }
//}

//void ColorMaker::stop()
//{
//    if(m_nColorTimer > 0)
//    {
//        killTimer(m_nColorTimer);
//        m_nColorTimer = 0;
//    }
//}

//void ColorMaker::timerEvent(QTimerEvent *e)
//{
//    if(e->timerId() == m_nColorTimer)
//    {
//        switch(m_algorithm)
//        {
//        case RandomRGB:
//            m_currentColor.setRgb(qrand() % 255, qrand() % 255, qrand() % 255);
//            break;
//        case RandomRed:
//            m_currentColor.setRed(qrand() % 255);
//            break;
//        case RandomGreen:
//            m_currentColor.setGreen(qrand() % 255);
//            break;
//        case RandomBlue:
//            m_currentColor.setBlue(qrand() % 255);
//            break;
//        case LinearIncrease:
//            {
//                int r = m_currentColor.red() + 10;
//                int g = m_currentColor.green() + 10;
//                int b = m_currentColor.blue() + 10;
//                m_currentColor.setRgb(r % 255, g % 255, b % 255);
//            }
//            break;
//        }
//        emit colorChanged(m_currentColor);
//        emit currentTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
//    }
//    else
//    {
//        QObject::timerEvent(e);
//    }
//}
