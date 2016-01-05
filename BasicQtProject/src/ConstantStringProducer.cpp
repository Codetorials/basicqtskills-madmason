#include "include/ConstantStringProducer.h"

#include <iostream>
#include <stdlib.h>

#include <QString>
#include <QVariant>

using namespace basicQt;


void ConstantStringProducer::run(){
    int x = rand();
    emit signal_stringCreated(new QVariant(x));
}
