#include "include/Worker.h"

#include <iostream>

using namespace basicQt;

Worker::Worker():
    QObject(),
    QRunnable() {

    setObjectName("Basic Worker");
}

void Worker::run(){
    std::cerr << "Basic worker implementation does not do anything." << std::endl;
}

