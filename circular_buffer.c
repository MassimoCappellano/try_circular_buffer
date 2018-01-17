#include <stdio.h>
#include "circular_buffer.h"


/****************************************************************************
 *
 * NAME: circBufPush
 *
 * DESCRIPTION: inserisce un comando nel circular buffer
 * 
 * RETURNS:
 *
 ****************************************************************************/
int circBufPush(circBuf_t *cb, DataCircularBuffer data)
{
      int next = cb->head + 1;
      if (next >= cb->maxLen) {
            next = 0;
      }
      // Cicular buffer is full
      if (next == cb->tail)
            return -1;  // quit with an error

      cb->buffer[cb->head] = data;
      cb->head = next;
      return 0;
}

/****************************************************************************
 *
 * NAME: circBufPop
 *
 * DESCRIPTION: elimina un comando dal circular buffer
 * 
 * RETURNS:
 *
 ****************************************************************************/
int circBufPop(circBuf_t *cb, DataCircularBuffer *data)
{
    // if the head isn't ahead of the tail, we don't have any characters
    if (cb->head == cb->tail) // check if circular buffer is empty
        return -1;          // and return with an error

    // next is where tail will point to after this read.
    int next = cb->tail + 1;
    if(next >= cb->maxLen) {
        next = 0;
    }
    *data = cb->buffer[cb->tail]; // Read data and then move
    cb->tail = next;             // tail to next data offset.
    return 0;  // return success to indicate successful push.
}

/****************************************************************************
 *
 * NAME: numElementsInBuffer
 *
 * DESCRIPTION: ritorna il numero di elementi nel circular buffer
 * 
 * RETURNS: num elementi
 *
 ****************************************************************************/

int numElementsInBuffer(circBuf_t *cb) 
{
      if(cb->head > cb-> tail) {
            return cb->head - cb-> tail;
      } else if (cb-> tail > cb->head) {
            return cb-> maxLen - cb-> tail + cb->head;
      } else {
            // equals head and tail
            return 0; // empty
      }
}


