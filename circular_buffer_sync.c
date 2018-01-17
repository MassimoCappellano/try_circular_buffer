#include <stdio.h>
#include <pthread.h>

#include "circular_buffer.h"

static pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

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
      pthread_mutex_lock( &mutex1 );
      int next = cb->head + 1;
      if (next >= cb->maxLen) {
            next = 0;
      }
      // Cicular buffer is full
      if (next == cb->tail) {
            pthread_mutex_unlock( &mutex1 );
            return -1;  // quit with an error
      }
      cb->buffer[cb->head] = data;
      cb->head = next;
      
      pthread_mutex_unlock( &mutex1 );
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
    pthread_mutex_lock( &mutex1 );  
    // if the head isn't ahead of the tail, we don't have any characters
    if (cb->head == cb->tail) {// check if circular buffer is empty
        pthread_mutex_unlock( &mutex1 );
        return -1;          // and return with an error
    }
    // next is where tail will point to after this read.
    int next = cb->tail + 1;
    if(next >= cb->maxLen) {
        next = 0;
    }
    *data = cb->buffer[cb->tail]; // Read data and then move
    cb->tail = next;             // tail to next data offset.
    
    pthread_mutex_unlock( &mutex1 );
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
      pthread_mutex_lock( &mutex1 );
      if(cb->head > cb-> tail) {
            int val = cb->head - cb-> tail;
            pthread_mutex_unlock( &mutex1 );
            return val;
      } else if (cb-> tail > cb->head) {
            int val = cb-> maxLen - cb-> tail + cb->head;
            pthread_mutex_unlock( &mutex1 );
            return val;
      } else {
            // equals head and tail
            pthread_mutex_unlock( &mutex1 );
            return 0; // empty
      }
}


