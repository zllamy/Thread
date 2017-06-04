#include "Consumer.h"
#include "global.h"
#include <QTime>
Consumer::Consumer()
{

}
void Consumer:: run()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    for (int i = 0; i < DataSize; ++i) {
                  mutex.lock();
                  if (numUsedBytes == 0)
                      bufferNotEmpty.wait(&mutex);
                  mutex.unlock();

                  fprintf(stderr, "%c", buffer[i % BufferSize]);

                  mutex.lock();
                  --numUsedBytes;
                  bufferNotFull.wakeAll();
                  mutex.unlock();
              }
              fprintf(stderr, "\n");
}
