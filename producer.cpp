#include "producer.h"
#include "global.h"
#include <QTime>
Producer::Producer()
{

}
void Producer:: run()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

             for (int i = 0; i < DataSize; ++i) {
                 mutex.lock();
                  if (numUsedBytes == BufferSize)
                     bufferNotFull.wait(&mutex);
                 mutex.unlock();

                 buffer[i % BufferSize] = "ACGT"[(int)qrand() % 4];

                 mutex.lock();
                 ++numUsedBytes;
                 bufferNotEmpty.wakeAll();
                 mutex.unlock();
             }
}
