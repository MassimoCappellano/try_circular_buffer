#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include "data_circular_buffer.h"


struct circBuf_t
{
      struct DataCircularBuffer *buffer;
      int head;
      int tail;
      int maxLen;
      int count;
};

int circBufPush(struct circBuf_t *cb, struct DataCircularBuffer data);

int circBufPop(struct circBuf_t *cb, struct DataCircularBuffer *data);

int numElementsInBuffer(struct circBuf_t *cb);

#endif