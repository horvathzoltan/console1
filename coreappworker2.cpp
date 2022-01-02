//#include "coreappworker2.h"

//CoreAppWorker2::CoreAppWorker2 (const Work1& w1) : _w1(w1)
//{
//    QObject::connect(this, &CoreAppWorker2::finished, QCoreApplication::instance(), QCoreApplication::quit, Qt::QueuedConnection);

//    //connect(this, finished, this, &QObject::deleteLater);

////    connect(this, &CoreAppWorker2::resultReady, a);
////    connect(this, &CoreAppWorker2::finished, this, &QObject::deleteLater);
////    connect(this, &CoreAppWorker2::finished, app, QCoreApplication::quit, Qt::QueuedConnection);
//}

//int CoreAppWorker2::run()
//{
//    int e = _w1.doWork();
//    emit finished();
//    return e;
//}
