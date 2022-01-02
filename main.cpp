#include <QCommandLineParser>
#include <QCoreApplication>
#include <QAbstractEventDispatcher>
#include "common/logger/log.h"
#include "appworker.h"
#include "common/helper/signalhelper/signalhelper.h"
#include "common/helper/CommandLineParserHelper/commandlineparserhelper.h"
//#include "common/coreappworker/coreappworker.h"
#include "work1.h"
//#include "coreappworker2.h"

auto main(int argc, char *argv[]) -> int
{
    com::helper::SignalHelper::setShutDownSignal(com::helper::SignalHelper::SIGINT_); // shut down on ctrl-c
    com::helper::SignalHelper::setShutDownSignal(com::helper::SignalHelper::SIGTERM_); // shut down on killall

    zInfo(QStringLiteral("started"));

    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName(QStringLiteral("test1"));

    QCommandLineParser parser;

    parser.setApplicationDescription(QStringLiteral("command line test1 app."));
    parser.addHelpOption();
    parser.addVersionOption();  

    const QString OPTION_IN = QStringLiteral("input");
    const QString OPTION_OUT = QStringLiteral("output");
    const QString OPTION_BACKUP = QStringLiteral("backup");

    com::helper::CommandLineParserHelper::addOption(&parser, OPTION_IN, QStringLiteral("gerber file as input"));
    com::helper::CommandLineParserHelper::addOption(&parser, OPTION_OUT, QStringLiteral("csv file as output"));
    com::helper::CommandLineParserHelper::addOptionBool(&parser, OPTION_BACKUP, QStringLiteral("set if backup is needed"));

    parser.process(app);

    bool isEventLoopNeeded = true;

    auto w1 =  new Work1(isEventLoopNeeded);

    bool isok = w1->init({
         parser.value(OPTION_IN),
         parser.value(OPTION_OUT),
         parser.isSet(OPTION_BACKUP)
    });

    if(!isok){
        return 1;
    }

    //Work1::Result a;
    //a = w1->doWork(); // indítás direkt
    w1->start(); // indítás szálon
    zInfo(QStringLiteral("waiting..."));

    int e = isEventLoopNeeded?QCoreApplication::exec():0;

    zInfo(w1->result.ToString());

    if(w1->result.state==Work1::Result::State::NotCalculated &&
        !isEventLoopNeeded) zInfo(QStringLiteral("NoEventLoop"));

    if(!e) zInfo(QStringLiteral("Everything went ok."));
    return e;
}


