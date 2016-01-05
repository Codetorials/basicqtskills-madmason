#ifndef PRINTCONSUMER_H
#define PRINTCONSUMER_H

#include <QObject>
#include <QVariant>

#include "Worker.h"

namespace basicQt {

class PrintConsumer :
        public Worker {
    Q_OBJECT

private:
    QVariant m_data;

public:
    PrintConsumer(QVariant data);
    void run();
};
}


#endif // PRINTCONSUMER_H
