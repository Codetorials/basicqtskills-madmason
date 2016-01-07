#include "include/IntProducer.h"

#include <iostream>
#include <stdlib.h>

#include <QMutex>
#include <QString>
#include <QVariant>


using namespace basicQt;

void IntProducer::run(){
    producerLock.lock();
    int x = rand();
    emit signal_intCreated(new QVariant(x));
    producerLock.unlock();
}

