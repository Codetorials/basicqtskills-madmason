
#include "PrintConsumer.h"

#include <iostream>

#include <QVariant>

namespace basicQt {

void PrintConsumer::run(){
    ConsumerWorker::outputLock.lock();
    std::cout << m_data.toString().toStdString() << std::endl;
    ConsumerWorker::outputLock.unlock();
}

}
