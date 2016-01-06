#include "include/Consumer.h"

#include <iostream>
#include <random>

#include <QMutexLocker>
#include <QString>
#include <QThreadPool>

#include "include/SpecialPrintConsumer.h"

using namespace basicQt;

Consumer::Consumer(QObject *parent) : QObject(parent)
{
    m_consumerThreads = new QThreadPool(this);
    std::random_device rd;
    mt = std::mt19937(rd());
}

void Consumer::slot_receiveData(QVariant *data){
    int x = data->value<int>();
    if (x == 0) {
        std::cout << x << std::endl;
    }
    ConsumerWorker* w = createWorker(*data);
    m_consumerThreads->start(w);
}

ConsumerWorker* Consumer::createWorker(QVariant data){
//    std::uniform_real_distribution<double> dist(1.0,2.0);
//    std::cout << dist(mt) << std::endl;
    return new SpecialPrintConsumer(data);
}

