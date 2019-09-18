#ifndef CLASS1_H
#define CLASS1_H

#include <QObject>
#include <QCommandLineParser>

class CoreAppWorker: public QObject
{
    Q_OBJECT    
public:
    CoreAppWorker(int (*fn)(), QCoreApplication *app, QCommandLineParser *parser);
    int doWork();
public slots:
    int run();
signals:
    void finished();
private:
    static int (*workerFn)();
    static QCommandLineParser* parser;
};

#endif // CLASS1_H
