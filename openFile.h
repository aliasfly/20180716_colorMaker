#ifndef OPENFILE_H
#define OPENFILE_H
#include <QObject>
#include "dataPlot.h"

class OpenFile : public QObject
{
    Q_OBJECT
public:
    OpenFile(QObject *parent = 0);
    ~OpenFile();
public slots:
    void ProduceRange();
    void ReadFile();
    void writeXML();
};

#endif // OPENFILE_H
