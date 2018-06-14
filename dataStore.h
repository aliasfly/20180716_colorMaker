#ifndef DATASTORE_H
#define DATASTORE_H
#include <QObject>

class DataStore  : public QObject
{
    Q_OBJECT
public:
    DataStore(QObject *parent = 0);
    ~DataStore();


};

#endif //DATASTORE_H
