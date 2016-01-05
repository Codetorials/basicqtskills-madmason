#ifndef CONSTANTSTRINGPRODUCER
#define CONSTANTSTRINGPRODUCER

#include <QObject>
#include <QRunnable>
#include <QVariant>

#include "ProducerWorker.h"

namespace basicQt {

class ConstantStringProducer :
        public ProducerWorker {
    Q_OBJECT
public:
    void test();
    void run();

signals:
    void signal_stringCreated(QVariant *value);
};


}
#endif // CONSTANTSTRINGPRODUCER

