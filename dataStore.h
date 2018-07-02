#ifndef DATASTORE_H
#define DATASTORE_H
#include <QObject>

class DataStore  : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float colorNumR READ colorNumR)
    Q_PROPERTY(float colorNumG READ colorNumG)
    Q_PROPERTY(float colorNumB READ colorNumB)

public:
    DataStore(QObject *parent = 0);
    ~DataStore();

    float colorNumR() const {return _colorNumR;}
    float colorNumG() const {return _colorNumG;}
    float colorNumB() const {return _colorNumB;}

signals:

public slots:
    void dealcolorR(int value);
    void dealcolorG(int value);
    void dealcolorB(int value);

private:
    float _colorNumR;
    float _colorNumG;
    float _colorNumB;
};

#endif //DATASTORE_H
