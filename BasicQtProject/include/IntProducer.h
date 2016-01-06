#ifndef INTPRODUCER
#define INTPRODUCER

#include <QObject>
#include <QRunnable>
#include <QVariant>

#include "ProducerWorker.h"

namespace basicQt {

/*
 *
 *
 */
class IntProducer :
        public ProducerWorker {
    Q_OBJECT
public:
    void run();

signals:
    void signal_intCreated(QVariant *value);
};


}
#endif // CONSTANTINTPRODUCER

