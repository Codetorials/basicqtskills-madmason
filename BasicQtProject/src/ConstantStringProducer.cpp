#include "include/ConstantStringProducer.h"

#include <iostream>

#include <QString>
#include <QVariant>

using namespace basicQt;

void ConstantStringProducer::test(){
    std::cerr << "test";
}

void ConstantStringProducer::run(){
    QString str = "Hello";
    emit signal_stringCreated(new QVariant(str));
}
