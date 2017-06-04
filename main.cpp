#include <QCoreApplication>
#include "producer.h"
#include "Consumer.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Producer producer;
         Consumer consumer;
         producer.start();
         consumer.start();
         producer.wait();
         consumer.wait();

    return a.exec();
}
