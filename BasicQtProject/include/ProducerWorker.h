#ifndef PRODUCERWORKER
#define PRODUCERWORKER

#include "Worker.h"

namespace basicQt {

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

