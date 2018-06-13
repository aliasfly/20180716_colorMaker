#include "colorMaker.h"
#include <QFile>
#include <QDebug>
#include <QByteArray>

//**********************
#include <QString>
#include <QXmlStreamWriter>
//**********************

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




void ColorMaker::writeXML() {
    QString strFile("Blogs.xml");
    QFile file(strFile);
    if (!file.open(QFile::WriteOnly | QFile::Text)) { // 只写模式打开文件
        qDebug() << QString("Cannot write file %1(%2).").arg(strFile).arg(file.errorString());
        return;
    }

    QXmlStreamWriter writer(&file);
    // writer.setCodec("GBK");  // XML 编码
    writer.setAutoFormatting(true); // 自动格式化
    writer.writeStartDocument("1.0", true);  // 开始文档（XML 声明）
    writer.writeComment(QString::fromLocal8Bit("纯正开源之美，有趣、好玩、靠谱。。。"));  // 注释
    writer.writeProcessingInstruction("xml-stylesheet type=\"text/css\" href=\"style.css\"");  // 处理指令

    // DTD
    writer.writeDTD(QString::fromLocal8Bit("<!DOCTYPE Blogs [ <!ENTITY Copyright \"Copyright 2016《Qt实战一二三》\"> <!ELEMENT Blogs (Blog)> <!ELEMENT Blog (作者,主页,个人说明)> <!ELEMENT 作者     (#PCDATA)> <!ELEMENT 主页     (#PCDATA)> <!ELEMENT 个人说明  (#PCDATA)> ]>"));

    writer.writeStartElement("Blogs");  // 开始根元素 <Blogs>
    writer.writeAttribute("Version", "1.0");  // 属性

    writer.writeStartElement("Blog");  // 开始子元素 <Blog>
    writer.writeTextElement(QString::fromLocal8Bit("作者"), QString::fromLocal8Bit("一去丶二三里"));
    writer.writeTextElement(QString::fromLocal8Bit("主页"), "http://blog.csdn.net/liang19890820");
    writer.writeTextElement(QString::fromLocal8Bit("个人说明"), QString::fromLocal8Bit("青春不老，奋斗不止！"));
    writer.writeEntityReference("Copyright");
    writer.writeCDATA(QString::fromLocal8Bit("<Qt分享&&交流>368241647</Qt分享&&交流>"));
    writer.writeCharacters(">");
    writer.writeEmptyElement(QString::fromLocal8Bit("Empty"));  // 空元素
    writer.writeEndElement();  // 结束子元素 </Blog>

    writer.writeEndElement();  // 结束根元素 </Blogs>
    writer.writeEndDocument();  // 结束文档

    qDebug()<<"writeXML finished!!!!!";

    file.close();  // 关闭文件
}
