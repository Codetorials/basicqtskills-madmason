#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include "Producer.h"
#include "Consumer.h"

#include <QCoreApplication>
#include <QVariant>

namespace basicQt {

class MyApplication :
        public QCoreApplication {
    Q_OBJECT
private:

    unsigned m_minProducerCount = 2;

    // TODO properly instantiate these, do not forget signal-slot connections
    Consumer *m_consumer;
    Producer *m_producer;

    /**
     * @brief parseCommandLineArguments takes the command line arguments and parses them.
     * The current implementation just prints them to stderr in a properly formatted fashion.
     * @param argc is the amount of arguments passed to the application.
     * Restiction: Should not be less then 1.
     * @param argv is the array of arguments actually given to the program as c-style strings.
     * Note: argv[0] is always the fully qualified path under which the application was called.
     */
    void parseCommandLineArguments();
    // Note: you may modify the implementation if you like.
    // e.g. change the min producer count
    // Just make sure to adapt the documentation as well

public:
    MyApplication(int argc, char** argv);
    ~MyApplication() = default;

    void setup();

signals:
    /**
     * @brief signal_producersRequired will be emitted once the application decides
     * that not enough producers are available.
     */
    void signal_producersRequired();

    /**
     * @brief signal_dataAvailable will be called once a producer worker has created new data
     * @param data are the data to be handed to a consumer worker.
     */
    void signal_dataAvailable(QVariant data);

public slots:
    void slot_producerFinished();
};
}
#endif // MYAPPLICATION_H
