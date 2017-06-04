#include <global.h>
const int DataSize = 10;


 char buffer[BufferSize];

 QWaitCondition bufferNotEmpty;
 QWaitCondition bufferNotFull;
 QMutex mutex;
 int numUsedBytes = 0;
