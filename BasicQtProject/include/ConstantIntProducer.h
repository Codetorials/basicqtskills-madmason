#ifndef CONSTANTINTPRODUCER
#define CONSTANTINTPRODUCER

#include <QObject>
#include <QRunnable>
#include <QVariant>

#include "ProducerWorker.h"

namespace basicQt {

class ConstantIntProducer :
        public ProducerWorker {
    Q_OBJECT
public:
    void run();

signals:
    void signal_intCreated(QVariant *value);
};


}
#endif // CONSTANTINTPRODUCER

