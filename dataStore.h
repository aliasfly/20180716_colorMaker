#ifndef DATASTORE_H
#define DATASTORE_H
#include <QObject>

class DataStore  : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float colorNumR READ colorNumR)
    Q_PROPERTY(float colorNumG READ colorNumG)
    Q_PROPERTY(float colorNumB READ colorNumB)
    Q_PROPERTY(float randColorNumR READ randColorNumR)
    Q_PROPERTY(float randColorNumG READ randColorNumG)
    Q_PROPERTY(float randColorNumB READ randColorNumB)
    Q_PROPERTY(float squareError READ squareError)
public:
    DataStore(QObject *parent = 0);
    ~DataStore();

    float colorNumR() const {return _colorNumR;}
    float colorNumG() const {return _colorNumG;}
    float colorNumB() const {return _colorNumB;}
    float randColorNumR() const {return _randColorNumR;}
    float randColorNumG() const {return _randColorNumG;}
    float randColorNumB() const {return _randColorNumB;}
    float squareError() const {return _squareError;}

signals:

public slots:
    void dealcolorR(int value);
    void dealcolorG(int value);
    void dealcolorB(int value);
    void produceRand();
    void calculateSquareError();

private:
    float _colorNumR;
    float _colorNumG;
    float _colorNumB;
    float _randColorNumR;
    float _randColorNumG;
    float _randColorNumB;
    float _squareError;
};

#endif //DATASTORE_H
