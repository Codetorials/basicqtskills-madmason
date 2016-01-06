#ifndef CONSUMERWORKER
#define CONSUMERWORKER

#include <QVariant>
#include <QMutex>

#include "Worker.h"

namespace basicQt {

class ConsumerWorker:
        public Worker{
    Q_OBJECT
public:
    ConsumerWorker(QVariant data) :
        m_data(data){
    }

protected:
    QVariant m_data;
    QMutex outputLock;
};
}

#endif // CONSUMERWORKER

