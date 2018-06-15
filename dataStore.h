#ifndef DATASTORE_H
#define DATASTORE_H
#include <QObject>
#include <QString>

class DataStore  : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int str READ str WRITE setStr NOTIFY strChanged)
    Q_PROPERTY(int str2 READ str2 WRITE setStr2 NOTIFY str2Changed)
    Q_PROPERTY(int str3 READ str3 WRITE setStr3 NOTIFY str3Changed)
public:
    DataStore(QObject *parent = 0);
    ~DataStore();

    int str() const;
    void setStr(const int &str);

    int str2() const;
    void setStr2(const int &str);

    int str3() const;
    void setStr3(const int &str);

signals:
    void strChanged(const int &str);
    void str2Changed(const int &str2);
    void str3Changed(const int &str3);
public slots:
    void getstr(int);

private:
    int AAA_currentstr;
    int BBB_currentstr;
    int CCC_currentstr;

};

#endif //DATASTORE_H
