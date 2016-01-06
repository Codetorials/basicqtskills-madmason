#include "MyApplication.h"

#include <iomanip>
#include <iostream>

#include <QStringList>
#include <QObject>

#include "include/ConstantIntProducer.h"
#include "include/Worker.h"
#include "include/Consumer.h"

using namespace basicQt;

MyApplication::MyApplication(int argc, char** argv):
                        QCoreApplication(argc, argv) {

    setObjectName("My Application");
    setApplicationName("A basic Qt application");
    setApplicationVersion("v2015.12.18");
    setOrganizationName("GWT-TUD");

    parseCommandLineArguments();

    m_consumer = new Consumer(this);
    m_producer = new Producer(this);
    QObject::connect(this,&MyApplication::signal_producersRequired,
                     m_producer, &Producer::slot_addProducer);
    std::cerr << "test2" << std::endl;
    setup();
}

void MyApplication::parseCommandLineArguments() {
    std::cerr << "Here are your command line arguments:" << std::endl;

    unsigned counter = 0;
    for(auto argument : arguments()){
        std::cerr << std::setw(3) << std::right << counter << " : " << argument.toStdString() << std::endl;
        counter++;
    }
}

void MyApplication::setup(){
    // Make sure there are sufficient producers at startup
    emit signal_producersRequired();
    emit signal_producersRequired();
}

void MyApplication::slot_producerFinished() {

    if(m_producer->workerCount() < m_minProducerCount) {
       emit signal_producersRequired();
    }
}
