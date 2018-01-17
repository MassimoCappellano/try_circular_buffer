#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include "data_circular_buffer.h"

#define CIRCBUFFER_DEF(x, y)  \
      DataCircularBuffer x##_dataSpace[y + 1];     \
      circBuf_t x = {               \
            .buffer = x##_dataSpace,      \
            .head = 0,                \
            .tail = 0,                \
            .maxLen = y + 1         \
      }

typedef struct 
{
      DataCircularBuffer * const buffer;
      int head;
      int tail;
      int maxLen;

} circBuf_t;

int circBufPush(circBuf_t *cb, DataCircularBuffer data);

int circBufPop(circBuf_t *cb, DataCircularBuffer *data);

int numElementsInBuffer(circBuf_t *cb);

#endif