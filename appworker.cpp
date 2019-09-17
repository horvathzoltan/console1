#include "appworker.h"
#include <QDebug>

AppWorker::AppWorker()
{

    qDebug() << "new AppWorker";
}

void AppWorker::doWork()
{
    auto m = new char[40];
    m=new char[2];
    qDebug() << "Class1 doWork()";
}

void AppWorker::run()
{
    doWork();
    // Same implementation as before
    // Emit signal when finished
    emit finished();
}

