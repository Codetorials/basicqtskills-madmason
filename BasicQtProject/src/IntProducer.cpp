#include "include/IntProducer.h"

#include <iostream>
#include <stdlib.h>

#include <QString>
#include <QVariant>

using namespace basicQt;

void IntProducer::run(){
    int x = rand();
    emit signal_intCreated(new QVariant(x));
}
