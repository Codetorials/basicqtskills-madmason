#include "include/Producer.h"

#include <iostream>

#include <QObject>

#include "include/IntProducer.h"
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
    IntProducer *producer = new IntProducer();
    QObject::connect(producer, &IntProducer::signal_intCreated,
                     m_consumer, &Consumer::slot_receiveData);
    MyApplication *app = qobject_cast <MyApplication *>(this->parent());
    QObject::connect(producer, &IntProducer::signal_producerFinished,
                     app, &MyApplication::slot_producerFinished);
    m_producerThreads->start(producer);
}
