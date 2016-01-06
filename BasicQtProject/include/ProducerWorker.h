#ifndef PRODUCERWORKER
#define PRODUCERWORKER

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


signals:
    void signal_producerFinished();
};
}

#endif // PRODUCERWORKER

