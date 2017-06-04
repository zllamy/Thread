#ifndef GLOBAL_H
#define GLOBAL_H
#include<QWaitCondition>
#include<QMutex>

extern const int DataSize ;

const int BufferSize = 8192;

extern char buffer[BufferSize];

extern QWaitCondition bufferNotEmpty;
extern QWaitCondition bufferNotFull;
extern QMutex mutex;
extern int numUsedBytes;

#endif // GLOBAL_H
