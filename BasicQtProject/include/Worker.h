/*
 * How to keep information alive over multiple runs of the same
 * consumer? (Multiple solutions are possible)
 */

#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QRunnable>

namespace basicQt {

class Worker :
        public QObject,
        public QRunnable {
    Q_OBJECT

public:
    explicit Worker();

    /*
     * This method is inherited from QRunnable and will be executed
     * in a seperate thread. Override this to achieve some actual
     * results. Remember to use some proper locking if necessary.
     */
    virtual void run();
};
}
#endif // WORKER_H
