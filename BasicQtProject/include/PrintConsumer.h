#ifndef PRINTCONSUMER_H
#define PRINTCONSUMER_H

#include <QObject>
#include <QVariant>

#include "ConsumerWorker.h"

namespace basicQt {

class PrintConsumer :
        public ConsumerWorker {
    Q_OBJECT

private:
    QVariant m_data;

public:
    PrintConsumer(QVariant data);
    void run();
};
}


#endif // PRINTCONSUMER_H
