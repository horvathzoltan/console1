#ifndef CLASS1_H
#define CLASS1_H

#include <QObject>



class Class1: public QObject
{
    Q_OBJECT
public:
    Class1();
    void doWork();
private slots:
    void run();
signals:
    void finished();
};

#endif // CLASS1_H
