
#include "SpecialPrintConsumer.h"

#include <iostream>
#include <stdlib.h>

#include <QVariant>

namespace basicQt {

void SpecialPrintConsumer::run(){
    if (m_data.canConvert<int>()) {
        ConsumerWorker::outputLock.lock();
        int x = rand();
        if (m_data.toInt() == x) {
            std::cout << x << std::endl;
        }
        ConsumerWorker::outputLock.unlock();
    }else{
        ConsumerWorker::outputLock.lock();
        std::cout << m_data.toString().toStdString() << std::endl;
        ConsumerWorker::outputLock.unlock();

    }
}

}
