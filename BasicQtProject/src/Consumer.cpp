#include "include/Consumer.h"

#include <iostream>

#include <QMutexLocker>

#include "include/PrintConsumer.h"

using namespace basicQt;

Consumer::Consumer(QObject *parent) : QObject(parent)
{

}

void Consumer::slot_receiveData(QVariant *data){
    std::cerr << data->String << " bla" << std::endl;
}
