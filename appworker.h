#ifndef CLASS1_H
#define CLASS1_H

#include <QObject>

class AppWorker: public QObject
{
    Q_OBJECT
public:
    AppWorker();
    void doWork();
public slots:
    void run();
signals:
    void finished();
};

#endif // CLASS1_H
