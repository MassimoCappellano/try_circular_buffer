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
int circBufPushORIG(circBuf_t *cb, DataCircularBuffer data)
{
      int next = cb->head + 1;
      if (next >= cb->maxLen)
            next = 0;

      // Cicular buffer is full
      if (next == cb->tail)
            return -1;  // quit with an error

      cb->buffer[cb->head] = data;
      cb->head = next;
      return 0;
}

int circBufPush(circBuf_t *cb, DataCircularBuffer data)
{
      // Cicular buffer is full
      if (cb->head == cb->tail && cb->count == cb->maxLen)
            return -1;  // quit with an error

      int next = cb->head + 1;
      if (next >= cb->maxLen)
            next = 0;

      cb->buffer[cb->head] = data;
      cb->head = next;
      cb->count ++;

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
      if (cb->head == cb->tail && cb->count == 0){

            return -1;  // quit with an error
      }
            

      *data = cb->buffer[cb->tail];
      //cb->buffer[cb->tail] = 0;  // clear the data (optional)

      int next = cb->tail + 1;
      if (next >= cb->maxLen)
            next = 0;

      cb->tail = next;
      cb->count--;

      return 0;
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
      return cb->count;
}


