#ifndef SPECIALPRINTCONSUMER_H
#define SPECIALPRINTCONSUMER_H

#include <QObject>
#include <QVariant>

#include "ConsumerWorker.h"

namespace basicQt {

/*
 * This consumer checks if the received data is an int that matches
 * a random int. If it matches the int will be printed.
 * If the received data is not an int the it will be printed as a string.
 */
class SpecialPrintConsumer :
        public ConsumerWorker {
    Q_OBJECT

private:

public:
    SpecialPrintConsumer(QVariant data):
        ConsumerWorker(data){
    }
    void run();
};
}


#endif // SPECIALPRINTCONSUMER_H
