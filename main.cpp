#include <QCommandLineParser>
#include <QCoreApplication>
#include <QTimer>
#include "common/logger/log.h"
#include "class1.h"

int main(int argc, char *argv[])
{
    zInfo(QStringLiteral("started"));

    QCoreApplication app(argc, argv);

    QCommandLineParser parser;
    QCoreApplication::setApplicationName(QStringLiteral("test1"));
    parser.setApplicationDescription(QStringLiteral("command line test1 app."));
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption m_opt(
        QStringList {"m" , "message"},
        QStringLiteral("translated messages"),
        QStringLiteral("messages")
        );
    parser.addOption(m_opt);

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

    zInfo(QStringLiteral("params: %1 %2 %3").arg(lFileName).arg(sFileName).arg(isBackup));

    Class1 c;
    QObject::connect(&c, SIGNAL(finished()), &app, SLOT(quit()));
    QTimer::singleShot(0, &c, SLOT(run()));

    auto e = QCoreApplication::exec();

    return e;
}
