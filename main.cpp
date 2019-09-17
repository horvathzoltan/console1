#include <QCommandLineParser>
#include <QCoreApplication>
#include <QTimer>
#include "common/logger/log.h"
#include "appworker.h"
#include "signalhelper.h"

int main(int argc, char *argv[])
{
    helpers::SignalHelper::setShutDownSignal(helpers::SignalHelper::SIGINT_); // shut down on ctrl-c
    helpers::SignalHelper::setShutDownSignal(helpers::SignalHelper::SIGTERM_); // shut down on killall

    zInfo(QStringLiteral("started"));

    QCoreApplication app(argc, argv);

    QCommandLineParser parser;
    QCoreApplication::setApplicationName(QStringLiteral("test1"));
    parser.setApplicationDescription(QStringLiteral("command line test1 app."));
    parser.addHelpOption();
    parser.addVersionOption();

    // -m
    QCommandLineOption m_opt(
        QStringList {"m" , "message"},
        QStringLiteral("translated messages"),
        QStringLiteral("messages")
        );
    parser.addOption(m_opt);

    // -s
    QCommandLineOption s_opt(
        QStringList {"s", "source"},
        QStringLiteral("source file"),
        QStringLiteral("source")
        );

    parser.addOption(s_opt);

    QCommandLineOption b_opt(
        QStringLiteral("backup"),
        QStringLiteral("backup file"));

    parser.addOption(b_opt);

    parser.process(app);

    QString lFileName = parser.value(m_opt);
    QString sFileName = parser.value(s_opt);
    bool isBackup= parser.isSet(b_opt);    

    AppWorker c;
    // break event loop
    QObject::connect(&c, &AppWorker::finished,&app, &QCoreApplication::quit, Qt::QueuedConnection);

    c.run();
    auto e = QCoreApplication::exec();
    return e;
}
