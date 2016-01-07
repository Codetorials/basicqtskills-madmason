#ifndef PRODUCERWORKER
#define PRODUCERWORKER

#include <QMutex>

#include "Worker.h"

namespace basicQt {

/*
 * Worker class for producers. Emits a signal once it gets destructed.
 */

class ProducerWorker :
        public Worker {
    Q_OBJECT

public:
    ~ProducerWorker(){
      emit signal_producerFinished();
    }
protected:
    QMutex producerLock;

signals:
    void signal_producerFinished();
};
}

#endif // PRODUCERWORKER

