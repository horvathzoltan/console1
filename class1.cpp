#include "class1.h"
#include <QDebug>

Class1::Class1()
{

    qDebug() << "new Class1";
}

void Class1::doWork()
{
    auto m = new char[40];
    m=new char[2];
    qDebug() << "Class1 doWork()";
}

void Class1::run()
{
    doWork();
    // Same implementation as before
    // Emit signal when finished
    emit finished();
}

