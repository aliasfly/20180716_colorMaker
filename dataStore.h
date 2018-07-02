#ifndef DATASTORE_H
#define DATASTORE_H
#include <QObject>

class DataStore  : public QObject
{
    Q_OBJECT
public:
    DataStore(QObject *parent = 0);
    ~DataStore();
signals:

public slots:
    void dealcolor();

private:
    float colorNum;
};

#endif //DATASTORE_H
