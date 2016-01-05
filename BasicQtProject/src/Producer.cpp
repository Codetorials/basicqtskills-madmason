#include "include/Producer.h"

#include <iostream>

#include <QObject>

#include "include/ConstantStringProducer.h"
#include "include/Consumer.h"
#include "include/MyApplication.h"

using namespace basicQt;

Producer::Producer(QObject *parent) :
                        QObject(parent){
    m_producerThreads = new QThreadPool(this);
    m_producerThreads->setMaxThreadCount(3);
    m_consumer = new Consumer(this);
}

unsigned Producer::workerCount(){
    return m_producerThreads->activeThreadCount();
}

void Producer::slot_addProducer(){
    ConstantStringProducer *producer = new ConstantStringProducer();
    QObject::connect(producer, &ConstantStringProducer::signal_stringCreated,
                     m_consumer, &Consumer::slot_receiveData);
    MyApplication *app = qobject_cast <MyApplication *>(this->parent());
    QObject::connect(producer, &ConstantStringProducer::signal_producerFinished,
                     app, &MyApplication::slot_producerFinished);
    m_producerThreads->start(producer);
}
