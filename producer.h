#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QThread>

class Producer : public QThread
{
public:
    Producer();
    void run();
};

#endif // PRODUCER_H
